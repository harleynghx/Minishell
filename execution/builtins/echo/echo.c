/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harleyng <harleyng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 14:16:25 by harleyng          #+#    #+#             */
/*   Updated: 2025/06/10 04:55:24 by harleyng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

static bool	is_flag_valid(char *arg)
{
	int	i;

	if (!arg || arg[0] != '-' || arg[1] != 'n')
		return (false);
	i = 2;
	while (arg[i])
	{
		if (arg[i] != 'n')
			return (false);
		i++;
	}
	return (true);
}

void	echo(t_shell *shell, char *cmd, char **args)
{
	int	i;

	if (!shell->print)
		return ;
	shell->exit_code = 0;
	if (!args[1])
	{
		write(1, "\n", 1);
		return ;
	}
	i = 1;
	while (args[i] && is_flag_valid(args[i]))
		i++;
	// Print args[i .. end]
	while (args[i])
	{
		print_without_quotes(args[i], 0, 0, 0);
		if (args[i + 1])
			write(1, " ", 1);
		i++;
	}
	if (!is_flag_valid(args[1]))
		write(1, "\n", 1);
}
