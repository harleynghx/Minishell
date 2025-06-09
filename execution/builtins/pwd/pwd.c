/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harleyng <harleyng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 14:17:13 by harleyng          #+#    #+#             */
/*   Updated: 2025/06/09 19:49:38 by harleyng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	pwd(t_shell *shell, char **args)
{
	t_env	*curr;

	curr = find_env_var(shell->env_head, "PWD");
	if (curr == NULL)
	{
		shell->exit_code = 1;
		if (shell->print == TRUE)
			p_err("%spwd: %s\n", SHELL, PWNED);
		return ;
	}
	if (shell->print == TRUE)
	{
		shell->exit_code = 0;
		printf("%s\n", curr->content);
	}
}
