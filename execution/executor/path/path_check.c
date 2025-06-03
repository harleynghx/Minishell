/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harleyng <harleyng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 14:18:40 by harleyng          #+#    #+#             */
/*   Updated: 2025/06/03 17:37:53 by harleyng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

/*
checks for:
../
./
.
/
and last check if we are in the folder of the executable
else
error
*/
static int	no_such_file_or_folder(char *command, t_shell *shell)
{
	shell->exit_code = 127;
	if (shell->print == TRUE)
		p_err("%s%s: %s\n", SHELL, command, strerror(ENOENT));
	return (FALSE);
}

static int	dot_dot_slash_at_path_start(t_shell *shell, char *path)
{
	if (access(path, X_OK) == 0)
		return (TRUE);
	else
		return (no_such_file_or_folder(path, shell), FALSE);
}

static int	dot_at_path_start(t_shell *shell, char *path)
{
	if (path[0] == '.' && access(path, X_OK) == 0)
		return (TRUE);
	return (no_such_file_or_folder(path, shell), FALSE);
}

static int	slash_at_path_start(t_shell *shell, char *path)
{
	if (access(path, X_OK) == 0)
		return (TRUE);
	else
		return (no_such_file_or_folder(path, shell), FALSE);
}
int	path_check(char *path, t_shell *shell)
{
	if (path[0] == '.' && path[1] == '.' && path[2] == '/'
		&& dot_dot_slash_at_path_start(shell, path) == TRUE)
		return (TRUE);
	if (path[0] == '.' && path[1] == '/' && ft_strlen(path) == 2)
		return (no_such_file_or_folder(shell->trimmed_prompt, shell), FALSE);
	if (path[0] == '.' || path[0] == '/' || path)
	{
		if (path[0] == '.' && path[1] != '/')
			return (invalid_command(shell, path), FALSE);
		else if (path[0] == '.' && dot_at_path_start(shell, path) == TRUE)
			return (TRUE);
		else if (path[0] == '/' && slash_at_path_start(shell, path) == TRUE)
			return (TRUE);
		else if (access(path, X_OK) == 0)
			return (TRUE);
		else if (shell->envless == TRUE)
			return (no_such_file_or_folder(path, shell), FALSE);
	}
	return (FALSE);
}

