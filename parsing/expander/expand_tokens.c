/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_tokens.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liyu-her <liyu-her@student.42.kl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 15:56:55 by liyu-her          #+#    #+#             */
/*   Updated: 2025/06/11 17:21:24 by liyu-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	expand_tables(t_cmd_tbl *tables, t_shell *shell)
{
	char	*cmd;

	while (tables != NULL)
	{
		cmd = NULL;
		cmd = expand_cmd(tables, shell);
		if (strcmp_2(cmd, "awk") == FALSE)
			expand_table(tables, shell);
		tables = tables->next;
		free(cmd);
	}
}

char	*expand_cmd(t_cmd_tbl *table, t_shell *shell)
{
	char	*result;
	int		i;

	i = 0;
	if (table->cmd == NULL)
		return (NULL);
	if (table->cmd[0] == '$')
		expander(&table->cmd, shell);
	result = ft_strdup(table->cmd);
	while (result[i] != '\0')
	{
		result[i] = ft_tolower(result[i]);
		i++;
	}
	return (result);
}

void	expand_table(t_cmd_tbl *table, t_shell *shell)
{
	expand_tokens(table->args, shell);
	expand_tokens(table->redirs, shell);
}

void	expand_tokens(t_token *tokens, t_shell *shell)
{
	while (tokens != NULL)
	{
		expander(&tokens->content, shell);
		tokens = tokens->next;
	}
}
