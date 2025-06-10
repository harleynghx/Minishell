/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liyu-her <liyu-her@student.42.kl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 15:57:06 by liyu-her          #+#    #+#             */
/*   Updated: 2025/06/04 13:13:13 by liyu-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

bool	has_dollar(char *str, t_shell *shell)
{
	int	i;

	i = -1;
	while (str[++i] != '\0')
	{
		if (str[0] == '$' && str[i + 1] != ' ' && str[i + 1] != '\0')
			return (TRUE);
		else if (str[i] == '$' && str[i + 1] == '\0')
			break ;
		else if ((str[i] == '$' && nb_esc_chars(str, i) % 2 != 0)
			|| (str[i] == '$' && dont_expand(str, i) == TRUE))
			i++;
		else if (str[i] == '$' && ft_pf_strchr(SPACES, str[i + 1]) != NULL)
		{
			shell->cmd_has_been_executed = FALSE;
			return (FALSE);
		}
		else if (str[i] == '$'
			&& ft_pf_strchr(SPACES, str[i + 1]) == NULL)
			return (TRUE);
	}
	return (FALSE);
}

void	copy_dollar_from_string(char **dst, char **s, int i)
{
	char	delim;
	int		j;
	int		sign;

	if (s[0][i + 1] == '?')
		dst[0] = ft_strdup2(s[0], i, i + 2);
	else
	{
		j = i;
		sign = i + 1;
		delim = ' ';
		if (s[0][i + 1] == '(')
			delim = ')';
		if (i > 0 && s[0][i - 1] == '\'' )
			delim = '\'';
		if (i > 0 && s[0][i - 1] == '\"' )
			delim = '\"';
		while (s[0][j] != '\0' && s[0][j] != delim && ((s[0][sign] >= 48
			&& 57 >= s[0][sign]) || (s[0][sign] >= 65 && 122 >= s[0][sign])))
		{
			j++;
			sign++;
		}
		dst[0] = ft_strdup2(s[0], i, j + 1);
	}
}

static void	extract_dollar(char **s, t_shell *sh, char **bf_sign, char **af_sign)
{
	int		i;
	char	**str;
	char	*val;

	str = malloc(sizeof(char *));
	i = -1;
	while (s[0][++i] != '\0')
	{
		if (s[0][i] == '$' && nb_esc_chars(s[0], i) % 2 == 0
			&& dont_expand(s[0], i) != TRUE)
		{
			bf_sign[0] = ft_strdup2(s[0], 0, i);
			copy_dollar_from_string(str, s, i);
			val = expand_dollars(str[0], sh);
			af_sign[0] = ft_strdup2(s[0], i + ft_strlen(*str), ft_strlen(s[0]));
			free(str[0]);
			*str = ft_strjoin(bf_sign[0], val);
			bf_sign[0] = ft_nm_strjoin(str[0], af_sign[0]);
			free(str[0]);
			free(str);
			free(s[0]);
			*s = *bf_sign;
			return ;
		}
	}
}

bool	expander(char **str, t_shell *shell)
{
	char	**before_dollar;
	char	**after_dollar;

	while (has_dollar(*str, shell) == TRUE)
	{
		before_dollar = malloc(sizeof(char *));
		after_dollar = malloc(sizeof(char *));
		extract_dollar(&*str, shell, before_dollar, after_dollar);
		free(after_dollar[0]);
		free(before_dollar);
		free(after_dollar);
	}
	return (TRUE);
}

char	*copy_variable(char *content)
{
	int		i;
	int		content_len;
	char	*var_content;

	i = -1;
	content_len = ft_strlen(content) + 1;
	var_content = malloc(sizeof(char) * content_len);
	while (content[++i] != '\0')
		var_content[i] = content[i];
	var_content[i] = '\0';
	return (var_content);
}
