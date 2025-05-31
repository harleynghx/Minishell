/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liyu-her <liyu-her@student.42.kl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 13:36:47 by liyu-her          #+#    #+#             */
/*   Updated: 2025/05/27 21:51:24 by liyu-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	nb_esc_chars(char *str, int last_ind)
{
	int	i;
	int	count;

	i = last_ind - 1;
	count = 0;
	if (last_ind <= 0)
		return (count);
	while (str[i] != -1)
	{
		if (str[i] == 92)
			count++;
		else if (str[i] != 92)
			return (count);
		i--;
	}
	return (count);
}

bool	syntax_error(char c)
{
	return (p_err(BOLD"%s%s `%c'\n"C_END, SHELL, SYNTAX_ERROR, c), TRUE);
}

bool	syntax_error_newline(void)
{
	return (p_err(BOLD"%s%s\n"C_END, SHELL, SYNTAX_ERROR_NEWLINE), TRUE);
}

bool	is_operator(char c)
{
	return (ft_pf_strchr(OPERATORS, c));
}
