/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liyu-her <liyu-her@student.42.kl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 05:30:02 by liyu-her          #+#    #+#             */
/*   Updated: 2025/05/31 14:50:00 by liyu-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	lexer(t_shell *shell)
{
	if (ft_strlen(shell->trimmed_prompt) == 0
		|| is_emptyline(shell) == TRUE)
		return (FALSE);
	else if (bad_pipe(shell) == TRUE)
		return (FALSE);
	else if (unclosed_quotes(shell->trimmed_prompt) == TRUE)
	{
		shell->cmd_has_been_executed = FALSE;
		return (FALSE);
	}
	else if (wrong_operator_check(shell->trimmed_prompt) == TRUE)
	{
		shell->exit_code = 2;
		shell->cmd_has_been_executed = FALSE;
	}
	return (TRUE);
}

// eg prompt -> ""
bool	is_emptyline(t_shell *s)
{
	if (s->trimmed_prompt[0] == '~' && ft_strlen(s->trimmed_prompt) == 1)
	{
		s->exit_code = 126;
		return (p_err("%s: %s: %s\n", SHELL, "~", ISDIR), TRUE);
	}
	if ((s->trimmed_prompt[0] == '>' && s->trimmed_prompt[1] == '>'
			&& s->trimmed_prompt[2] == '>') || (s->trimmed_prompt[0] == '<'
			&& s->trimmed_prompt[1] == '<' && s->trimmed_prompt[2] == '<'))
	{
		s->exit_code = 2;
		return (syntax_error(s->trimmed_prompt[0]), TRUE);
	}
	if (s->trimmed_prompt[0] == DQUOTE && s->trimmed_prompt[1] == DQUOTE
		&& ft_strlen(s->trimmed_prompt) == 2)
	{
		p_err("%s: %s\n", SHELL, CMD_NOT_FND);
		s->cmd_has_been_executed = FALSE;
		s->exit_code = 127;
		return (TRUE);
	}
	return (FALSE);
}

/*
checks if there is only space between operators and if so,
returns syntax error at the index of it's occourance
*/
bool	wrong_operator_check(char *str)
{
	int	i;

	i = 0;
	if (has_wrong_pipe(str))
		return (TRUE);
	while (str[++i])
	{
		if (is_operator(str[i - 1]) && is_space(str[i]))
		{
			i = skip_spaces(str, i);
			if (is_operator(str[i]))
			{
				if (str[i] == '<' && str[i + 1] == '<')
					return (FALSE);
				else
					return (syntax_error(str[i]), TRUE);
			}
		}
	}
	if (is_operator(str[ft_strlen(str) - 1]))
		return (syntax_error_newline(), TRUE);
	return (FALSE);
}

bool	bad_pipe(t_shell *shell)
{
	int	len;

	len = ft_strlen(shell->trimmed_prompt) - 1;
	if (shell->trimmed_prompt[0] == '|')
	{
		shell->exit_code = 2;
		return (syntax_error(shell->trimmed_prompt[0]), TRUE);
	}
	else if (shell->trimmed_prompt[len] == '|')
	{
		shell->exit_code = 2;
		return (syntax_error_newline(), TRUE);
	}
	return (FALSE);
}
