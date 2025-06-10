/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_options.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harleyng <harleyng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 14:01:31 by harleyng          #+#    #+#             */
/*   Updated: 2025/06/10 19:24:21 by harleyng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	cd_home(t_shell *shell)
{
	t_env	*home;

	home = find_env_var(shell->env_head, "HOME");
	if (!home || !home->content || !*home->content)
	{
		shell->exit_code = 1;
		if (shell->print == TRUE)
			p_err("%scd: %s\n", SHELL, HOMELESS);
		return ;
	}
	if (chdir(home->content) == -1)
	{
		shell->exit_code = 1;
		if (shell->print == TRUE)
			p_err("%scd: %s: %s\n", SHELL, home->content, strerror(errno));
	}
}
static char	*get_home_path(t_shell *shell, char *folder_path)
{
	t_env	*home;
	char	*suffix;

	home = find_env_var(shell->env_head, "HOME");
	if (!home || !home->content)
	{
		shell->exit_code = 1;
		if (shell->print)
			p_err("%scd: HOME not set\n", SHELL);
		return (NULL);
	}
	suffix = folder_path + 1;
	return (ft_nm_strjoin(home->content, suffix));
}

void	cd_tilde(t_shell *shell, char *folder_path)
{
	char	*full_path;

	if (folder_path[0] != '~' || (folder_path[1] && folder_path[1] != '/'))
	{
		if (chdir(folder_path) == -1 && shell->print)
			p_err("%scd: %s: %s\n", SHELL, folder_path, strerror(errno));
		return ;
	}
	full_path = shell->envless ? ft_nm_strjoin("/Users/",
			shell->user_name) : get_home_path(shell, folder_path);
	if (!full_path)
		return ;
	if (chdir(full_path) == -1 && shell->print)
		p_err("%scd: %s: %s\n", SHELL, full_path, strerror(errno));
	free(full_path);
}

void	cd_oldpwd(t_shell *shell)
{
	t_env	*oldpwd;

	if (shell->prev_prompt == NULL || shell->envless)
	{
		cd_oldpwd_fallback(shell);
		return ;
	}
	oldpwd = find_env_var(shell->env_head, "OLDPWD");
	if (!oldpwd || !oldpwd->content)
	{
		shell->exit_code = 1;
		if (shell->print)
			p_err("%scd: OLDPWD not set\n", SHELL);
		return ;
	}
	if (chdir(oldpwd->content) == -1)
	{
		shell->exit_code = 1;
		if (shell->print)
			p_err("%scd: %s: %s\n", SHELL, oldpwd->content, strerror(errno));
		return ;
	}
	if (shell->print)
		printf("%s\n", oldpwd->content);
}

void	cd_back(t_shell *shell, char *path, char *display_path)
{
	if (chdir(path) == -1)
	{
		shell->exit_code = 1;
		if (shell->print == TRUE)
		{
			if (display_path)
				p_err("%scd: %s: %s\n", SHELL, display_path, strerror(errno));
			else
				p_err("%scd: %s: %s\n", SHELL, path, strerror(errno));
		}
	}
}
void	cd_forward(t_shell *shell, char *folder_path)
{
	if (chdir(folder_path) == -1)
	{
		shell->exit_code = 1;
		if (shell->print == TRUE)
			p_err("%scd: %s: %s\n", SHELL, folder_path, strerror(errno));
	}
}
