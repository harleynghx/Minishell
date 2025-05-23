/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_heredoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harleyng <harleyng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 14:18:22 by harleyng          #+#    #+#             */
/*   Updated: 2025/05/19 14:20:00 by harleyng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	open_heredoc(t_cmd_tbl *table, t_shell *shell, t_token *token)
{
	int	fd;

	if (is_last_heredoc(token, table->redirs) == false)
		return (-99);
	dup2(shell->std_fds[0], STDIN_FILENO);
	fd = open(table->heredoc_name, O_RDONLY);
	return (fd);
}

bool	is_last_heredoc(t_token *token, t_token *redirs)
{
	t_token	*heredoc;

	heredoc = NULL;
	while (redirs != NULL)
	{
		if (redirs->type == HEREDOC)
			heredoc = redirs;
		redirs = redirs->next;
	}
	if (heredoc == token)
		return (true);
	return (false);
}
