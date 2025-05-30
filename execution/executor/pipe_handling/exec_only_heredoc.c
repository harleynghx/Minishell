/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_only_heredoc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harleyng <harleyng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 14:18:52 by harleyng          #+#    #+#             */
/*   Updated: 2025/05/29 20:37:01 by harleyng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

static bool	invalid_redirection(t_token *token)
{
	while (token != NULL)
	{
		if (is_good_redirection(token) == false)
			return (true);
		token = token->next->next;
	}
	return (false);
}
static void	initiate_heredocs(t_cmd_tbl *start, t_cmd_tbl *last, t_shell *sh)
{
	t_token	*token;
	char	*tmp;

	while (start != last->next)
	{
		token = start->redirs;
		while (token != NULL)
		{
			if (is_redirection(token) && is_redirection(token->next))
				return ;
			if (token->type == HEREDOC)
			{
				tmp = stop_word(token->next->content, sh);
				free(token->next->content);
				token->next->content = tmp;
				start->heredoc_name = heredoc(start, token->next->content, sh);
			}
			token = token->next;
		}
		start = start->next;
	}
}
bool	validate_redir_initiate_heredocs(t_cmd_tbl *table, t_shell *shell)
{
	bool		flag;
	t_cmd_tbl	*current_tbl;

	flag = false;
	current_tbl = table;
	while (current_tbl != NULL && flag == false)
	{
		flag = invalid_redirection(current_tbl->redirs);
		if (flag == true)
			break ;
		current_tbl = current_tbl->next;
	}
	if (flag == true && current_tbl != NULL)
	{
		initiate_heredocs(table, current_tbl, shell);
		return (true);
	}
	return (false);
}
