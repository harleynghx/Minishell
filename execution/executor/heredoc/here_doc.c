/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harleyng <harleyng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 14:18:15 by harleyng          #+#    #+#             */
/*   Updated: 2025/06/10 18:57:55 by harleyng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

static bool	cmd_tbl_has_heredoc(t_cmd_tbl *cmd_tbl)
{
	t_token	*token;

	if (cmd_tbl == NULL)
		return (FALSE);
	token = cmd_tbl->redirs;
	while (token != NULL)
	{
		if (token->type == HEREDOC)
			return (TRUE);
		token = token->next;
	}
	return (FALSE);
}
static char	*filename(t_cmd_tbl *table)
{
	char	*tmp;
	char	*tmp1;
	char	*i;

	if (table->heredoc_name != NULL)
	{
		unlink(table->heredoc_name);
		return (table->heredoc_name);
	}
	i = ft_itoa(table->index);
	tmp = ft_nm_strjoin(TMP_S, i);
	free(i);
	tmp1 = ft_nm_strjoin(tmp, TMP_E);
	free(tmp);
	unlink(tmp1);
	return (tmp1);
}

static void	execute_heredocs(t_cmd_tbl *cmd_tbl, t_shell *shell)
{
	t_token	*token;
	char	*tmp;

	token = cmd_tbl->redirs;
	while (token != NULL)
	{
		if (token->type == HEREDOC)
		{
			tmp = stop_word(token->next->content, shell);
			free(token->next->content);
			token->next->content = tmp;
			cmd_tbl->heredoc_name = heredoc(cmd_tbl, token->next->content,
					shell);
		}
		token = token->next;
	}
}
char	*heredoc(t_cmd_tbl *cmd_tbl, char *s_w, t_shell *shell)
{
	int		fd;
	char	*input;

	cmd_tbl->heredoc_name = filename(cmd_tbl);
	fd = open(cmd_tbl->heredoc_name, O_RDWR | O_CREAT | O_EXCL, 0600);
	if (fd == -1)
		p_err("%s%s\n", SHELL, strerror(errno));
	while (1)
	{
		write(1, "> ", 2);
		input = get_next_line(STDIN_FILENO);
		if (heredocs_break(shell, input, s_w))
		{
			free(input);
			break ;
		}
		if (shell->expand_heredoc == TRUE)
			expander(&input, shell);
		write(fd, input, ft_strlen(input));
		free(input);
	}
	shell->should_expand = FALSE;
	return (close(fd), cmd_tbl->heredoc_name);
}

void	handle_heredocs(t_cmd_tbl *cmd_tbl, t_shell *shell)
{
	while (cmd_tbl != NULL)
	{
		if (cmd_tbl_has_heredoc(cmd_tbl) == TRUE)
			execute_heredocs(cmd_tbl, shell);
		cmd_tbl = cmd_tbl->next;
	}
}
