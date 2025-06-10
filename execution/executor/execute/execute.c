/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liyu-her <liyu-her@student.42.kl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 14:17:59 by harleyng          #+#    #+#             */
/*   Updated: 2025/06/10 15:46:27 by liyu-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

/*
table has wrong redir:
	exec heredocs but only until the point of the error
	delete the tmp files, nothing else executes
	exit
handle heredocs:
	execute all heredocs
	save the filenames in array
execute a simple command
execute commands on a pipeline
*/
void	execute(t_shell *shell, t_cmd_tbl *table)
{
	bool	is_invalid;

	is_invalid = invalid_redir_and_initiate_heredocs(table, shell);
	if (is_invalid)
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
