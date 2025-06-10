/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liyu-her <liyu-her@student.42.kl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 15:03:18 by liyu-her          #+#    #+#             */
/*   Updated: 2025/06/07 01:27:04 by liyu-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	init_shell(t_shell *shell, char **env)
{
	shell->envless = FALSE;
	shell->color_codes = TRUE;
	shell->env_head = init_env(env);
	shell->user_name = getenv("USER");
	shell->cmd_paths = ft_split(get_path(env), ':');
	shell->env = NULL;
	shell->exit_code = 0;
	shell->print = FALSE;
	shell->heredoc = NULL;
	shell->cmd_tbls = NULL;
	shell->prev_prompt = NULL;
	shell->trimmed_prompt = NULL;
	shell->terminal_prompt = NULL;
	shell->heredoc_ctrl = FALSE;
	shell->cmd_has_been_executed = TRUE;
	shell->std_fds[0] = dup(STDIN_FILENO);
	shell->std_fds[1] = dup(STDOUT_FILENO);
}
