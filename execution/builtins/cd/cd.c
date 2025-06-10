/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harleyng <harleyng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 14:16:08 by harleyng          #+#    #+#             */
/*   Updated: 2025/06/10 23:15:35 by harleyng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	cd(t_shell *shell, char **args)
{
	t_env	*pwd_var;
	char	*old_pwd_copy;
	char	*target;

	pwd_var = find_env_var(shell->env_head, "PWD");
	if (!pwd_var || !pwd_var->content)
		return ;
	old_pwd_copy = ft_strdup(pwd_var->content);
	if (!old_pwd_copy)
		return ;
	target = args[1];
	if (!target)
		cd_home(shell);
	else if (target[0] == '~')
		cd_tilde(shell, target);
	else if (ft_strcmp(target, "-") == TRUE)
		cd_oldpwd(shell);
	else if (ft_strcmp(target, "..") == 0 || ft_strncmp(target, "../", 3) == 0)
		cd_back(shell, target, args[2]);
	else
		cd_forward(shell, target);
	update_pwd_and_oldpwd(shell, old_pwd_copy);
	free(old_pwd_copy);
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
	if (shell->envless)
		full_path = ft_nm_strjoin("/Users/", shell->user_name);
	else
		full_path = get_home_path(shell, folder_path);
	if (!full_path)
		return ;
	if (chdir(full_path) == -1 && shell->print)
		p_err("%scd: %s: %s\n", SHELL, full_path, strerror(errno));
	free(full_path);
}
