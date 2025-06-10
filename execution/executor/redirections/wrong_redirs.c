/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrong_redirs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harleyng <harleyng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 14:19:08 by harleyng          #+#    #+#             */
/*   Updated: 2025/06/10 19:25:43 by harleyng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

static void	execute_only_heredocs(t_shell *shll, t_cmd_tbl *tabl, t_token *end)
{
	t_token	*start;
	char	*tmp;

	start = tabl->redirs;
	while (start != end && start != NULL)
	{
		if (start->type == HEREDOC)
		{
			tmp = stop_word(start->next->content, shll);
			free(start->next->content);
			start->next->content = tmp;
			heredoc(tabl, start->next->content, shll);
		}
		start = start->next;
	}
}

bool	has_wrong_redir(t_shell *shell, t_token *token, t_cmd_tbl *table)
{
	t_token	*current_token;

	current_token = token;
	while (current_token != NULL)
	{
		if (is_redirection(current_token) == FALSE)
		{
			current_token = current_token->next;
			continue ;
		}
		if (is_good_redirection(current_token) == FALSE)
			break ;
		current_token = current_token->next->next;
	}
	if (current_token == NULL)
		return (FALSE);
	execute_only_heredocs(shell, table, current_token);
	return (TRUE);
}
