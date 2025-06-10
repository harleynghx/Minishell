/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liyu-her <liyu-her@student.42kl.edy.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 15:03:38 by liyu-her          #+#    #+#             */
/*   Updated: 2025/06/10 21:11:05 by liyu-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	g_ctrl_c = 0;

int	main(int argc, char **argv, char **env)
{
	t_shell	shell;

	ft_arg(argc);
	init_shell(&shell, env);
	shell_loop(&shell);
	free_at_exit(&shell);
	exit(shell.exit_code);
}
