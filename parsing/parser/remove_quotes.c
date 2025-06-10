/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liyu-her <liyu-her@student.42.kl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 15:48:25 by liyu-her          #+#    #+#             */
/*   Updated: 2025/06/04 16:28:20 by liyu-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static char	*rm_quotes(char *str)
{
	char	*result;
	int		i;

	if (str[0] == SQUOTE || str[0] == DQUOTE)
	{
		result = ft_strdup2(str, 1, ft_strlen(str) - 1);
		return (result);
	}
	return (ft_strdup(str));
}

static void	rm_quotes_tokens(t_token *tokens, t_shell *shell, t_token *args)
{
	char	*tmp;

	while (tokens != NULL)
	{
		if (tokens->type == HEREDOC)
		{
			tokens = tokens->next;
			if (tokens != NULL)
				tokens = tokens->next;
			if (tokens == NULL)
				return ;
		}
		tmp = rm_quotes(tokens->content);
		free(tokens->content);
		tokens->content = tmp;
		tokens = tokens->next;
	}
}

static void	rm_quotes_token(t_token *tokens, t_shell *shell)
{
	char	*tmp;

	while (tokens != NULL)
	{
		if (tokens->type == HEREDOC)
		{
			tokens = tokens->next;
			if (tokens != NULL)
				tokens = tokens->next;
			if (tokens == NULL)
				return ;
		}
		tmp = rm_quotes(tokens->content);
		free(tokens->content);
		tokens->content = tmp;
		tokens = tokens->next;
	}
}

static void	rm_quotes_table(t_cmd_tbl *table, t_shell *shell)
{
	rm_quotes_token(table->args, shell);
	rm_quotes_tokens(table->redirs, shell, table->args);
}

void	rm_quotes_tables(t_cmd_tbl *tables, t_shell *shell)
{
	char	*tmp;

	while (tables != NULL)
	{
		if (tables->cmd != NULL)
		{
			tmp = rm_quotes(tables->cmd);
			free(tables->cmd);
			tables->cmd = tmp;
			cmd_to_lower_case(tables);
		}
		if (strcmp_2(tables->cmd, "echo") == FALSE
			&& strcmp_2(tables->cmd, "export") == FALSE)
			rm_quotes_table(tables, shell);
		tables = tables->next;
	}
}
