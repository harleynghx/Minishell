/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harleyng <harleyng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 20:01:04 by zstenger          #+#    #+#             */
/*   Updated: 2025/05/19 14:06:27 by harleyng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	signals(struct termios *mirror_termios)
{
	g_ctrl_c = FALSE;
	save_settings_and_remove_c(mirror_termios);
	signal_ctrl_backslash();
	signal_ctrl_c();
}

void	save_settings_and_remove_c(struct termios *mirror_termios)
{
	struct termios		termios_settings;

	tcgetattr(1, mirror_termios);
	tcgetattr(1, &termios_settings);
	termios_settings.c_lflag &= ~ECHOCTL;
	tcsetattr(1, TCSAFLUSH, &termios_settings);
}

void	signal_ctrl_c(void)
{
	struct sigaction	ctrl_c;

	ctrl_c.sa_handler = handle_sigint;
	ctrl_c.sa_flags = SA_RESTART;
	sigemptyset(&ctrl_c.sa_mask);
	sigaction(SIGINT, &ctrl_c, NULL);
}

void	signal_ctrl_backslash(void)
{
	struct sigaction	ctrl_back_slash;

	ctrl_back_slash.sa_handler = SIG_IGN;
	ctrl_back_slash.sa_flags = SA_RESTART;
	sigemptyset(&ctrl_back_slash.sa_mask);
	sigaction(SIGQUIT, &ctrl_back_slash, NULL);
}

void	handle_sigint(int sig_num)
{
	if (sig_num == SIGINT)
	{
		g_ctrl_c = TRUE;
		write(1, "\n", 2);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}
