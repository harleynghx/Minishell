/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liyu-her <liyu-her@student.42.kl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 14:19:27 by harleyng          #+#    #+#             */
/*   Updated: 2025/06/06 12:56:11 by liyu-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	signals(struct termios *mirror_termios)
{
	g_ctrl_c = FALSE;
	handle_signals(mirror_termios);
	signal_backslash();
	signal_c();
}

void	handle_signals(struct termios *mirror_termios)
{
	struct termios	termios_settings;

	tcgetattr(1, mirror_termios);
	tcgetattr(1, &termios_settings);
	termios_settings.c_lflag &= ~ECHOCTL;
	tcsetattr(1, TCSAFLUSH, &termios_settings);
}

void	signal_c(void)
{
	struct sigaction	ctrl_c;

	ctrl_c.sa_handler = handle_sigint;
	ctrl_c.sa_flags = SA_RESTART;
	sigemptyset(&ctrl_c.sa_mask);
	sigaction(SIGINT, &ctrl_c, NULL);
}

void	signal_backslash(void)
{
	struct sigaction	ctrl_backslash;

	ctrl_backslash.sa_handler = SIG_IGN;
	ctrl_backslash.sa_flags = SA_RESTART;
	sigemptyset(&ctrl_backslash.sa_mask);
	sigaction(SIGQUIT, &ctrl_backslash, NULL);
}

void	handle_sigint(int sig_num)
{
	if (sig_num == SIGINT)
	{
		g_ctrl_c = TRUE;
		write(1, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}
