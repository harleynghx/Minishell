/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liyu-her <liyu-her@student.42.kl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 14:18:08 by harleyng          #+#    #+#             */
/*   Updated: 2025/06/08 01:20:35 by liyu-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

char	*stop_word(char *str, t_shell *shell)
{
	int		i;
	char	*trim;
	char	*result;

	i = 0;
	shell->expand_heredoc = TRUE;
	while (str[i] != '\0')
	{
		if (str[i] == SQUOTE || str[i] == DQUOTE)
			shell->expand_heredoc = FALSE;
		i++;
	}
	trim = malloc(sizeof(char) * 3);
	trim[0] = SQUOTE;
	trim[1] = DQUOTE;
	trim[2] = '\0';
	result = ft_strtrim(str, trim);
	free(trim);
	return (result);
}

bool heredocs_break(t_shell *shell, char *input, char *s_w)
{
	if (g_ctrl_c == TRUE || input == NULL || (ft_strncmp(input, s_w,
			ft_strlen(s_w)) == 0 && ((ft_strlen(input)
				- 1) == ft_strlen(s_w))))
				{
					shell->heredoc_ctrl = TRUE;
					return (TRUE);
				}
	return (FALSE);
}
