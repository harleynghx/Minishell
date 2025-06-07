/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harleyng <harleyng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 14:16:08 by harleyng          #+#    #+#             */
/*   Updated: 2025/06/07 23:25:53 by harleyng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	cd(t_shell *shell, char *cmd, char **args)
{
	t_env	*pwd_var;
	char	*old_pwd_copy;
	char	*target;

	(void)cmd;
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
	else if (ft_strcmp(target, "-") == 0)
		cd_oldpwd(shell);
	else if (ft_strcmp(target, "..") == 0 || ft_strncmp(target, "../", 3) == 0)
		cd_back(shell, target, args[2]);
	else
		cd_forward(shell, target);
	update_pwd_and_oldpwd(shell, old_pwd_copy);
	free(old_pwd_copy);
}
