/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liyu-her <liyu-her@student.42.kl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 12:54:21 by liyu-her          #+#    #+#             */
/*   Updated: 2025/05/27 18:42:50 by liyu-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

bool	is_only_space(char *str)
{
	int	i;

	i = -1;
	while (str[++i] != '\0')
	{
		if (str[i] != ' ')
			return (FALSE);
	}
	return (TRUE);
}

bool	repeating_prompt(char *prompt, char *prev_prompt)
{
	if (prev_prompt == NULL || ft_strcmp(prompt, prev_prompt) == FALSE)
		return (FALSE);
	return (TRUE);
}

bool	add_history_if(char *prompt, char *prev_prompt)
{
	if (prompt[0] != '\0' && is_only_space(prompt) == FALSE
		&& repeating_prompt(prompt, prev_prompt) == FALSE)
	{
		if (prev_prompt != NULL)
			free(prev_prompt);
		add_history(prompt);
		return (TRUE);
	}
	return (FALSE);
}

int	cmd(t_shell *shell, char *str, int s)
{
	if (ft_strncmp(shell->trimmed_prompt, str, s) == 0)
		return (1);
	return (0);
}
