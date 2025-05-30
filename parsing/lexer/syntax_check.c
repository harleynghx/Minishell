/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harleyng <harleyng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 12:47:49 by zstenger          #+#    #+#             */
/*   Updated: 2025/05/30 18:02:06 by harleyng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

bool	contains_triple_redirection(char *str)
{
	int	len;
	int	i;

	if (!str)
		return (FALSE);
	len = ft_strlen(str);
	if (len < 3)
		return (FALSE);
	i = 0;
	while (i <= len - 3)
	{
		if ((str[i] == '>' && str[i + 1] == '>' && str[i + 2] == '>')
			|| (str[i] == '<' && str[i + 1] == '<' && str[i + 2] == '<'))
		{
			syntax_error(str[i]);
			return (TRUE);
		}
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
				return (syntax_error(str[i]), TRUE);
		}
	}
	return (FALSE);
}

bool	redir_before(char *str, int i)
{
	if (ft_pf_strchr(REDIRECTIONS, str[i - 1]) && str[i - 2] != 92)
		return (TRUE);
	if (ft_pf_strchr(REDIRECTIONS, str[i - 1]) && str[i - 2] == 92)
		if (nb_esc_chars(str, i - 1) % 2 == 0)
			return (TRUE);
	return (FALSE);
}
