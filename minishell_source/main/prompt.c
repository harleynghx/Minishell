/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liyu-her <liyu-her@student.42kl.edy.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 14:31:10 by zstenger          #+#    #+#             */
/*   Updated: 2025/06/10 23:54:38 by liyu-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	terminal_prompt(t_shell *shell)
{
	char	*full;
	char	*directory;

	if (shell->terminal_prompt != NULL)
		free(shell->terminal_prompt);
	directory = curr_dir(shell);
	full = ft_nm_strjoin(directory, " $ ");
	free(directory);
	shell->terminal_prompt = full;
	shell->cmd_has_been_executed = TRUE;
}

char	*curr_dir(t_shell *shell)
{
	int		i;
	t_env	*pwd;
	char	**split;
	char	*directory;

	i = 0;
	pwd = find_env_var(shell->env_head, "PWD");
	if (ft_strcmp(pwd->content, "/") == TRUE)
		directory = ft_strdup("/");
	else
	{
		split = ft_split(pwd->content, '/');
		while (split[i] != NULL)
			i++;
		directory = ft_strdup(split[--i]);
		free_char_array(split);
	}
	return (directory);
}
