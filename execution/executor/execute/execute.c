/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liyu-her <liyu-her@student.42.kl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 14:17:59 by harleyng          #+#    #+#             */
/*   Updated: 2025/06/10 18:44:46 by liyu-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	execute(t_shell *shell, t_cmd_tbl *table)
{
	if (invalid_redir_and_initiate_heredocs(table, shell))
	{
		contains_triple_redirection(shell->trimmed_prompt);
		shell->exit_code = 258;
	}
	else
	{
		handle_heredocs(table, shell);
		if (g_ctrl_c == FALSE && table)
		{
			if (!table->next && table_size(table) == 1)
				exec_without_pipes(table, shell);
			else
			{
				shell->exec_on_pipe = TRUE;
				exec_pipes(table, shell);
			}
		}
	}
	free_cmd_tbls(shell->cmd_tbls);
	shell->cmd_tbls = NULL;
}

int	table_size(t_cmd_tbl *table)
{
	int	i;

	i = 0;
	while (table != NULL)
	{
		i++;
		table = table->next;
	}
	return (i);
}
