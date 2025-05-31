/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals_parent.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liyu-her <liyu-her@student.42.kl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 14:19:23 by harleyng          #+#    #+#             */
/*   Updated: 2025/05/28 16:54:57 by liyu-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	signals_parent(void)
{
	signal_ctrl_c_parent();
	signal_backslash();
}

void	handle_sigint_parent(int sig_num)
{
	if (sig_num == SIGINT)
	{
		write(1, "^C\n", 3);
		rl_on_new_line();
		rl_replace_line("", 0);
	}
}

void	signal_ctrl_c_parent(void)
{
	struct sigaction	ctrl_c;

	ctrl_c.sa_handler = handle_sigint_parent;
	ctrl_c.sa_flags = SA_RESTART;
	sigemptyset(&ctrl_c.sa_mask);
	sigaction(SIGINT, &ctrl_c, NULL);
}
