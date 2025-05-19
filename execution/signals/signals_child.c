/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals_child.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harleyng <harleyng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 14:19:18 by harleyng          #+#    #+#             */
/*   Updated: 2025/05/19 14:19:37 by harleyng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	signals_child(struct termios *mirror_termios)
{
	tcsetattr(1, TCSAFLUSH, mirror_termios);
	signal_ctrl_backslash();
	signal_ctrl_c_child();
}

void	signal_ctrl_c_child(void)
{
	struct sigaction	ctrl_c;

	ctrl_c.sa_handler = SIG_DFL;
	ctrl_c.sa_flags = SA_RESTART;
	sigemptyset(&ctrl_c.sa_mask);
	sigaction(SIGINT, &ctrl_c, NULL);
}

void	signal_ctrl_backslash_child(void)
{
	struct sigaction	ctrl_back_slash;

	ctrl_back_slash.sa_handler = SIG_DFL;
	ctrl_back_slash.sa_flags = SA_RESTART;
	sigemptyset(&ctrl_back_slash.sa_mask);
	sigaction(SIGQUIT, &ctrl_back_slash, NULL);
}
