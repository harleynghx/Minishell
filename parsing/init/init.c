/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liyu-her <liyu-her@student.42.kl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 08:17:42 by zstenger          #+#    #+#             */
/*   Updated: 2025/05/20 13:41:54 by liyu-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	init_shell(t_shell *shell, char **env)
{
	t_token	token;


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
	shell->cmd_has_been_executed = TRUE;
	shell->std_fds[0] = dup(STDIN_FILENO);
	shell->std_fds[1] = dup(STDOUT_FILENO);
}
