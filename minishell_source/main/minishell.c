/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liyu-her <liyu-her@student.42.kl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 15:03:38 by liyu-her          #+#    #+#             */
/*   Updated: 2025/05/27 18:28:56 by liyu-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	main(int argc, char **argv, char **env)
{
	t_shell	shell;

	ft_arg(argc);
	init_shell(&shell, env);
	shell_loop(&shell);
	free_at_exit(&shell);
	exit(shell.exit_code);
}
