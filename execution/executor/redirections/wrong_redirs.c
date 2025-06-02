/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrong_redirs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harleyng <harleyng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 14:19:08 by harleyng          #+#    #+#             */
/*   Updated: 2025/06/02 13:18:47 by harleyng         ###   ########.fr       */
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
	t_token	*wrong;

	wrong = token;
	while (wrong != NULL)
	{
		if (is_redirection(wrong) == false)
		{
			wrong = wrong->next;
			continue ;
		}
		if (is_good_redirection(wrong) == false)
			break ;
		wrong = wrong->next->next;
	}
	if (wrong == NULL)
		return (false);
	execute_only_heredocs(shell, table, wrong);
	return (true);
}
