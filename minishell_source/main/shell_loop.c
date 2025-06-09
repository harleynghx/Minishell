/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harleyng <harleyng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 15:03:53 by liyu-her          #+#    #+#             */
/*   Updated: 2025/06/10 03:36:14 by harleyng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	shell_loop(t_shell *shell)
{
	while (TRUE)
	{
		signals(&shell->mirror_termios);
		terminal_prompt(shell);
		if (read_line(shell) == NULL)
			break ;
		update_env(shell);
		if (lexer(shell) == TRUE && parser(shell) == TRUE)
			execute(shell, shell->cmd_tbls);
		addhistory(shell);
	}
}

int	*read_line(t_shell *shell)
{
	char	*line;

	shell->exec_on_pipe = FALSE;
	shell->should_execute = FALSE;
	if (isatty(fileno(stdin)))
		shell->prompt = readline(shell->terminal_prompt);
	else
	{
		line = get_next_line(fileno(stdin));
		shell->prompt = ft_strtrim(line, "\n");
		free(line);
	}
	shell->trimmed_prompt = ft_strtrim(shell->prompt, SPACES);
	g_ctrl_c = FALSE;
	if (shell->prompt == NULL)
		return (NULL);
	return ((void *)1);
}

void	update_env(t_shell *shell)
{
	if (shell->env != NULL)
		free_char_array(shell->env);
	shell->env = env_list_to_char(shell->env_head);
}

void	addhistory(t_shell *shell)
{
	t_token	*token;

	if (add_history_if(shell->prompt, shell->prev_prompt) == TRUE)
		shell->prev_prompt = shell->prompt;
	else
		free(shell->prompt);
	free(shell->trimmed_prompt);
	if (shell->exit_code == 0)
		shell->cmd_has_been_executed = TRUE;
	else
		shell->cmd_has_been_executed = FALSE;
}
