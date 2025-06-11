/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liyu-her <liyu-her@student.42.kl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 19:34:34 by harleyng          #+#    #+#             */
/*   Updated: 2025/06/11 17:16:38 by liyu-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static bool	is_valid_var_char(char c)
{
	return ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z') || (c >= 'a'
			&& c <= 'z'));
}

static char	determine_delimiter(char *str, int i)
{
	if (str[i + 1] == '(')
		return (')');
	if (i > 0 && str[i - 1] == '\'')
		return ('\'');
	if (i > 0 && str[i - 1] == '\"')
		return ('\"');
	return (' ');
}

static void	handle_special_dollar(char **dst, char *s, int i)
{
	if (s[i + 1] == '?')
		*dst = ft_strdup2(s, i, i + 2);
}

static void	extract_variable(char **dst, char *s, int i, char delim)
{
	int	j;
	int	sign;

	j = i;
	sign = i + 1;
	while (s[j] && s[j] != delim && is_valid_var_char(s[sign]))
	{
		j++;
		sign++;
	}
	*dst = ft_strdup2(s, i, j + 1);
}

void	copy_dollar_from_string(char **dst, char **s, int i)
{
	char	delim;

	if (!s || !*s || !dst)
		return ;
	handle_special_dollar(dst, *s, i);
	if (*dst)
		return ;
	delim = determine_delimiter(*s, i);
	extract_variable(dst, *s, i, delim);
}
