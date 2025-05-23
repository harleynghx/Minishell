/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harleyng <harleyng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 14:16:08 by harleyng          #+#    #+#             */
/*   Updated: 2025/05/19 14:21:03 by harleyng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	cd(t_shell *shell, char *cmd, char **args)
{
	t_env	*old_pwd;
	char	*old_pwd_content;

	old_pwd = find_env_var(shell->env_head, "PWD");
	old_pwd_content = old_pwd->content;
	if (args[1] == NULL)
		cd_home(shell);
	else if (args[1][0] == '~')
		cd_tilde(shell, args[1]);
	else if (strcmp_2(args[1], "-") == TRUE)
		cd_oldpwd(shell);
	else if (args[1] != NULL && ft_strcmp(args[1], "..") != 1
		&& args[1][0] != '-')
		cd_forward(shell, args[1]);
	else if (ft_strcmp(args[1], "..") == TRUE || ft_strncmp(args[1], "../",
			3) == 0)
		cd_back(shell, args[1], args[2]);
	update_pwd_and_oldpwd(shell, old_pwd->content);
}
