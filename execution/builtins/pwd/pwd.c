/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harleyng <harleyng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 14:17:13 by harleyng          #+#    #+#             */
/*   Updated: 2025/05/19 14:20:39 by harleyng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	pwd(t_shell *shell, char **args)
{
	t_env	*curr;

	curr = shell->env_head;
	if (find_env_var(shell->env_head, "PWD") == NULL)
	{
		shell->exit_code = 1;
		if (shell->print == TRUE)
			p_err("%spwd: %s\n", SHELL, PWNED);
	}
	while (curr->next != NULL)
	{
		if (ft_strncmp(curr->var_name, "PWD", 3) == 0)
		{
			if (shell->print == TRUE)
			{
				shell->exit_code = 0;
				printf("%s\n", curr->content);
			}
			return ;
		}
		else
			curr = curr->next;
	}
}
