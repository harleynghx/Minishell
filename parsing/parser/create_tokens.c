/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tokens.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liyu-her <liyu-her@student.42.kl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 19:46:09 by liyu-her          #+#    #+#             */
/*   Updated: 2025/06/02 21:41:08 by liyu-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/* 
split_elements_to_tokens takes one pipe (str) and token
as input. Function takes token as argument to save space.
Function uses i and start as indexes to create a new token
from position start to i. And returns the head of token.
 */
t_token	*tokenize(char *str, t_token *token)
{
	int	i;
	int	start;

	i = 0;
	while (str[i] != '\0')
	{
		start = i;
		token = token_quote(str, &i, &start, token);
		token = token_word(str, &i, &start, token);
		token = token_redir(str, &i, &start, token);
		token = token_flag(str, &i, &start, token);
		i = skip_spaces(str, i);
	}
	return (token);
}

t_token	*token_quote(char *str, int *i, int *start, t_token *token)
{
	char	quote;
	bool	stop;

	if (str[*i] == '\0')
		return (token);
	if (str[*i] != SQUOTE && str[*i] != DQUOTE)
		return (token);
	quote = str[(*i)++];
	stop = false;
	while (str[*i] != '\0' && stop == false)
	{
		if (str[*i] == quote && nb_esc_chars(str, *i) % 2 == 0)
			stop = true;
		(*i)++;
	}
	if (*i - 1 != *start)
		token = add_new_token(token, ft_strdup2(str, *start, *i), WORD);
	*start = *i;
	return (token);
}

t_token	*token_word(char *str, int *i, int *start, t_token *token)
{
	while ((ft_isalpha(str[*i]) || ft_isalnum(str[*i])
			|| is_printable(str[*i]))
		&& str[*i] != '\0')
		(*i)++;
	if (*i != *start)
	{
		token = add_new_token(token, ft_strdup2(str, *start, *i), WORD);
		*start = *i;
	}
	return (token);
}

t_token	*token_redir(char *str, int *i, int *start, t_token *tk)
{
	char	redirection;
	t_type	rdir_type;

	if (str[*i] == '\0'
		|| ft_pf_strchr(REDIRECTIONS, str[*i]) == NULL)
		return (tk);
	redirection = str[*i];
	while (str[*i] == redirection
		&& str[*i] != '\0')
		(*i)++;
	rdir_type = get_redirection_type(str, *start, *i);
	tk = add_new_token(tk, ft_strdup2(str, *start, *i), rdir_type);
	*start = *i;
	return (tk);
}

t_token	*token_flag(char *str, int *i, int *start, t_token *token)
{
	if (str[*i] != '-')
		return (token);
	(*i)++;
	while (str[*i] != '\0' && str[*i] != ' ')
	{
		if (ft_isalpha(str[*i]) == 0
			&& str[*i] != '-'
			&& ft_isalnum(str[*i]))
			break ;
		(*i)++;
	}
	token = add_new_token(token, ft_strdup2(str, *start, *i), WORD);
	*start = *i;
	return (token);
}
