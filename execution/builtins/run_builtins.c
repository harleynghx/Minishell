/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_builtins.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harleyng <harleyng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 14:20:28 by harleyng          #+#    #+#             */
/*   Updated: 2025/06/09 23:37:59 by harleyng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

bool	builtins(t_shell *shell, char *cmd, char **args)
{
	if (ft_strcmp(cmd, C_D) == TRUE && shell->exec_on_pipe == FALSE)
		return (cd(shell, args), TRUE);
	else if (ft_strcmp(cmd, "cd") == TRUE && shell->exec_on_pipe == FALSE)
		return (cd(shell, args), TRUE);
	else if (ft_strcmp(cmd, "pwd") == TRUE && shell->should_execute == TRUE)
		return (pwd(shell), TRUE);
	else if (ft_strcmp(cmd, "export") == TRUE && shell->should_execute == TRUE)
		return (export(shell, cmd, args), TRUE);
	else if (ft_strcmp(cmd, "env") == TRUE && shell->should_execute == TRUE)
		return (env(shell, args), TRUE);
	else if (ft_strcmp(cmd, "exit") == TRUE)
		return (exit_shell(shell, cmd, args), TRUE);
	else if (ft_strcmp(cmd, "unset") == TRUE && shell->should_execute == TRUE)
		return (unset(shell, cmd, args), TRUE);
	else if (ft_strcmp(cmd, "echo") == TRUE && shell->should_execute == TRUE)
		return (call_echo(shell, cmd, args), TRUE);
	if (shell->envless == TRUE)
		shell->exit_code = 127;
	return (FALSE);
}

void	call_echo(t_shell *shell, char *cmd, char **args)
{
	echo(shell, cmd, args);
	if (shell->exit_code != 127)
		shell->exit_code = 0;
}
