/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harleyng <harleyng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 14:16:52 by harleyng          #+#    #+#             */
/*   Updated: 2025/06/10 19:58:55 by harleyng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	simple_exit(t_shell *shell)
{
	free_at_exit(shell);
	exit(0);
}

void	exit_tma(t_shell *shell, char *cmd)
{
	if (shell->print == TRUE)
		p_err("%s%s: %s\n", SHELL, cmd, TMA);
	free_at_exit(shell);
	exit(255);
}

void	exit_code(t_shell *shell, char **args)
{
	int	i;
	int	len;
	int	code;

	i = 5;
	len = ft_strlen(args[1]);
	if (is_exit_code_correct(shell, args[1], 0))
		code = shell->exit_code;
	else
	{
		code = 255;
		if (shell->print == TRUE)
			p_err("%s%s: %s", SHELL, args[0], NAR);
		free_at_exit(shell);
		exit(code);
	}
	code = shell->exit_code;
	free_at_exit(shell);
	exit(code);
}

void	exit_code_on_pipe(t_shell *shell, char **args)
{
	char	*code_str;

	code_str = ft_strdup(args[1]);
	if (code_str == NULL)
	{
		if (shell->print == TRUE)
			p_err("%s%s\n", SHELL, MALLOC_FAIL);
		free_at_exit(shell);
		exit(EXIT_FAILURE);
	}
	shell->exit_code = ft_atoi(code_str);
	free(code_str);
	exit(shell->exit_code);
}
