/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harleyng <harleyng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 14:16:25 by harleyng          #+#    #+#             */
/*   Updated: 2025/06/10 03:27:15 by harleyng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

static bool	is_flag_valid(char *arg)
{
	int	i;

	if (!arg || arg[0] != '-' || arg[1] != 'n')
		return (FALSE);
	i = 2;
	while (arg[i])
	{
		if (arg[i] != 'n')
			return (FALSE);
		i++;
	}
	return (TRUE);
}
static int	echo_n_flag_validator(char **args)
{
	int	i;

	i = 1;
	while (args[i] && is_flag_valid(args[i]))
		i++;
	return (i);
}

static void	simple_echo(t_shell *shell, char **args)
{
	int	j;

	j = 1;
	while (args[j])
	{
		print_without_quotes(args[j], 0, 0, 0);
		if (args[j + 1])
			write(1, " ", 1);
		j++;
	}
	write(1, "\n", 1);
}
static void	handle_n_flag(char **args)
{
	int	j;

	j = echo_n_flag_validator(args);
	if (!args[j])
		return ;
	while (args[j])
	{
		print_without_quotes(args[j], 0, 0, 0);
		if (args[j + 1])
			write(1, " ", 1);
		j++;
	}
}
void	echo(t_shell *shell, char *cmd, char **args)
{
	if (!shell->print)
		return ;
	shell->exit_code = 0;
	if (!args[1])
	{
		write(1, "\n", 1);
		return ;
	}
	if (is_flag_valid(args[1]))
		handle_n_flag(args);
	else
		simple_echo(shell, args);
}
