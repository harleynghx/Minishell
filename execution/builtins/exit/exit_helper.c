/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harleyng <harleyng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 19:59:23 by harleyng          #+#    #+#             */
/*   Updated: 2025/06/10 20:00:00 by harleyng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

static int	ft_isnumeric(const char *str)
{
	int	i;

	if (!str || *str == '\0')
		return (0);
	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

static void	handle_pipe_exit(t_shell *shell, char *cmd, char **args)
{
	if (!args[1])
		shell->exit_code = 0;
	else if (ft_isnumeric(args[1]) && !args[2])
		shell->exit_code = ft_atoi(args[1]) % 256;
	else
	{
		if (shell->print && args[1])
			p_err("%s%s: %s: numeric argument required\n", SHELL, cmd,
				args[1]);
		shell->exit_code = 255;
	}
}

static void	handle_non_numeric_arg(t_shell *shell, char *cmd, char *arg)
{
	if (shell->print)
		p_err("%s%s: %s: numeric argument required\n", SHELL, cmd, arg);
	shell->exit_code = 255;
	simple_exit(shell);
}

static void	handle_too_many_args(t_shell *shell, char *cmd)
{
	if (shell->print)
		p_err("%s%s: too many arguments\n", SHELL, cmd);
	shell->exit_code = 1;
}

void	exit_shell(t_shell *shell, char *cmd, char **args)
{
	if (shell->exec_on_pipe)
	{
		handle_pipe_exit(shell, cmd, args);
		return ;
	}
	if (!args[1])
	{
		simple_exit(shell);
		return ;
	}
	if (ft_strlen(args[1]) == 0)
	{
		exit_tma(shell, cmd);
		return ;
	}
	if (args[2] != NULL)
	{
		handle_too_many_args(shell, cmd);
		return ;
	}
	if (ft_isnumeric(args[1]))
		exit_code(shell, args);
	else
		handle_non_numeric_arg(shell, cmd, args[1]);
}
