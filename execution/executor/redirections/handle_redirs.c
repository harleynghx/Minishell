/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_redirs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harleyng <harleyng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 03:05:46 by harleyng          #+#    #+#             */
/*   Updated: 2025/06/03 16:12:23 by harleyng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

static t_token	*set_curr(t_token *curr)
{
	if (curr->next != NULL)
		curr = curr->next->next;
	else
		curr = curr->next;
	return (curr);
}
static bool	std_out_error(t_shell *shell)
{
	shell->exit_code = errno;
	if (shell->print == TRUE)
		p_err("%s%s\n", SHELL, strerror(errno));
	return (TRUE);
}
static bool	change_stdin_out(t_type type, int fd, t_shell *shell, int ret_val)
{
	if (type == HEREDOC)
	{
		ret_val = dup2(fd, STDIN_FILENO);
		close(fd);
		unlink("/tmp/heredoc.XXXXXX");
	}
	if (type == INPUT)
	{
		if (fd == -1)
			return (FALSE);
		ret_val = dup2(fd, STDIN_FILENO);
		close(fd);
	}
	else if (type == OUTPUT || type == APPEND)
	{
		ret_val = dup2(fd, STDOUT_FILENO);
		close(fd);
	}
	if (ret_val == -1)
		if (std_out_error(shell) == TRUE)
			return (free_at_child(shell), FALSE);
	return (TRUE);
}


void	handle_redirections(t_shell *shell, t_cmd_tbl *table)
{
	t_token	*curr;
	int		fd;

	curr = table->redirs;
	while (curr != NULL)
	{
		if (is_good_redirection(curr) == FALSE)
		{
			shell->exit_code = 258;
			return ;
		}
		if (curr->type == HEREDOC && curr->next->type == WORD)
			fd = open_heredoc(table, shell, curr);
		else if (curr->type == OUTPUT && curr->next->type == WORD)
			fd = open_file(OUTPUT, curr->next->content, shell);
		else if (curr->type == APPEND && curr->next->type == WORD)
			fd = open_file(APPEND, curr->next->content, shell);
		else if (curr->type == INPUT && curr->next->type == WORD)
			fd = open_file(INPUT, curr->next->content, shell);
		if (fd != -99 && change_stdin_out(curr->type, fd, shell, 0) == FALSE)
			exit(1);
		curr = set_curr(curr);
	}
}

bool	is_good_redirection(t_token *token)
{
	if (is_redirection(token) && token->next != NULL
		&& !is_redirection(token->next))
		return (TRUE);
	return (FALSE);
}

