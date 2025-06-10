/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harleyng <harleyng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 14:16:25 by harleyng          #+#    #+#             */
/*   Updated: 2025/06/10 06:10:30 by harleyng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	is_flag_valid(char *s)
{
	int	i;

	i = 1;
	if (!s || s[0] != '-' || s[1] != 'n')
		return (0);
	while (s[i] == 'n')
		i++;
	return (s[i] == '\0');
}

void	echo(t_shell *shell, char *cmd, char **args)
{
	int	i;
	int	newline;

	i = 1;
	newline = 1;
	(void)cmd;
	if (!shell->print)
		return ;
	shell->exit_code = 0;
	while (args[i] && is_flag_valid(args[i]))
	{
		newline = 0;
		i++;
	}
	while (args[i])
	{
		ft_putstr_fd(args[i], 1);
		if (args[i + 1])
			write(1, " ", 1);
		i++;
	}
	if (newline)
		write(1, "\n", 1);
}
