/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harleyng <harleyng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 12:47:49 by zstenger          #+#    #+#             */
/*   Updated: 2025/05/30 17:39:41 by harleyng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

bool	contains_triple_redirection(char *str)
{
	int	i;

	i = 0;
	while (ft_strlen(str) > 2 && i != ft_strlen(str) - 2)
	{
		if (str[i] == '>' && str[i + 1] == '>' && str[i + 2] == '>')
			return (syntax_error(str[i]), TRUE);
		i++;
	}
	i = 0;
	while (ft_strlen(str) > 2 && i != ft_strlen(str) - 2)
	{
		if (str[i] == '<' && str[i + 1] == '<' && str[i + 2] == '<')
			return (syntax_error(str[i]), TRUE);
		i++;
	}
	return (FALSE);
}

bool	has_wrong_pipe(char *str)
{
	int	i;

	i = 0;
	while (str[++i] != '\0')
	{
		if (str[i] == '|')
		{
			if (redir_before(str, i))
				return (syntax_error(str[i]), true);
		}
	}
	return (false);
}

bool	redir_before(char *str, int i)
{
	if (ft_pf_strchr(REDIRECTIONS, str[i - 1]) && str[i - 2] != 92)
		return (true);
	if (ft_pf_strchr(REDIRECTIONS, str[i - 1]) && str[i - 2] == 92)
		if (nb_esc_chars(str, i - 1) % 2 == 0)
			return (true);
	return (false);
}
