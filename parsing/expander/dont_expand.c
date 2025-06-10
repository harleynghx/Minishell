/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dont_expand.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harleyng <harleyng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 17:36:59 by liyu-her          #+#    #+#             */
/*   Updated: 2025/06/10 19:28:06 by harleyng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static bool	dont_expand_result(char *str, int i, int dq, int sq)
{
	int	j;

	j = i;
	while (i != -1)
	{
		if (str[i] == SQUOTE && nb_esc_chars(str, i) % 2 == 0)
			sq++;
		if (str[i] == DQUOTE && nb_esc_chars(str, i) % 2 == 0)
			dq++;
		i--;
	}
	if (sq == 1 && dq == 0)
		return (TRUE);
	else if (sq == 1 && dq == 1 && str[j - 1] == DQUOTE)
		return (TRUE);
	else if (sq == 2 && dq == 1)
		return (FALSE);
	else if (sq == 1 && dq == 2 && str[j - 1] == SQUOTE)
		return (TRUE);
	else if (sq == 2 && dq == 2 && str[j - 1] == SQUOTE && str[j - 3] == SQUOTE)
		return (TRUE);
	else if (sq == 4 && dq == 3)
		return (TRUE);
	return (FALSE);
}

bool	dont_expand(char *str, int i)
{
	if (i == 0)
		return (FALSE);
	if (i > 0 && (str[i + 1] == DQUOTE || str[i + 1] == SQUOTE))
		return (TRUE);
	return (dont_expand_result(str, i, 0, 0));
}
