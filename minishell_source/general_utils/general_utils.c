/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liyu-her <liyu-her@student.42.kl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 18:43:22 by liyu-her          #+#    #+#             */
/*   Updated: 2025/05/27 18:43:23 by liyu-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	cmd_to_lover_case(t_cmd_tbl *table)
{
	char	*result;

	result = ft_strdup(table->cmd);
	convert_to_lower(result, ft_strlen(result));
	if (strcmp_2(result, "echo")
		|| strcmp_2(result, "pwd")
		|| strcmp_2(result, "env"))
		convert_to_lower(table->cmd, ft_strlen(table->cmd));
	free(result);
}

int	skip_spaces(char *str, int index)
{
	while (str[index] != '\0'
		&& is_space(str[index]))
		index++;
	return (index);
}

int	ft_isupper(char c)
{
	return (c >= 'A' && c <= 'Z');
}

bool	is_space(char c)
{
	return (ft_pf_strchr(SPACES, c));
}

bool	convert_to_lower(char *str, int until)
{
	int	len;
	int	i;

	i = 0;
	len = strlen(str);
	while (i < len && i < until)
	{
		if (isupper(str[i]))
			str[i] = tolower(str[i]);
		i++;
	}
	return (TRUE);
}
