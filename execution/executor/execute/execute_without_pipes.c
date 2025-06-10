/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_without_pipes.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liyu-her <liyu-her@student.42.kl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 14:20:09 by harleyng          #+#    #+#             */
/*   Updated: 2025/06/10 16:10:23 by liyu-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

static void	simple_exec_in_child(t_shell *shell, t_cmd_tbl *table)
{
	signals_child(&shell->mirror_termios);
	if (has_wrong_redir(shell, table->redirs, table) == FALSE)
	{
		shell->print = TRUE;
		handle_redirections(shell, table);
		execute_command(table, shell);
	}
	child_exit(shell);
}
void	exec_without_pipes(t_cmd_tbl *table, t_shell *shell)
{
	int		status;
	pid_t	pid;

	pid = fork();
	shell->exec_on_pipe = FALSE;
	shell->should_execute = TRUE;
	if (pid == -1)
	{
		if (shell->print == TRUE)
			p_err("%s%s\n", SHELL, FORK_ERROR);
	}
	else if (pid == 0)
		simple_exec_in_child(shell, table);
	waitpid_to_get_exit_status(pid, shell, &status);
	if (table->cmd != NULL)
		builtins(shell, table->cmd, table->cmd_args);
	if (has_wrong_redir(shell, table->redirs, table) == FALSE)
		reset_io_streams(shell);
	else
		shell->exit_code = 258;
}

