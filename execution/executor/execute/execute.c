/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harleyng <harleyng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 14:17:59 by harleyng          #+#    #+#             */
/*   Updated: 2025/05/28 18:24:47 by harleyng         ###   ########.fr       */
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
	if (validate_redir_initiate_heredocs(table, shell) == true)
	{
		redir_check(shell->trimmed_prompt);
		shell->exit_code = 258;
		free_cmd_tbls(shell->cmd_tbls);
		shell->cmd_tbls = NULL;
		return ;
	}
	handle_heredocs(table, shell);
	if (g_ctrl_c == FALSE && table != NULL && table->next == NULL
		&& table_size(table) == 1)
		exec_without_pipes(table, shell);
	else if (g_ctrl_c == FALSE && table != NULL && table->next != NULL)
	{
		shell->exec_on_pipe = TRUE;
		exec_pipes(table, shell);
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
