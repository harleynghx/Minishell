/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liyu-her <liyu-her@student.42.kl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 14:17:36 by harleyng          #+#    #+#             */
/*   Updated: 2025/05/27 18:51:14 by liyu-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	free_char_array(char **array)
{
	int	i;

	if (array == NULL)
		return ;
	i = 0;
	while (array[i] != NULL)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	free_env(t_env *head)
{
	t_env	*next;

	while (head != NULL)
	{
		next = head->next;
		free(head->var_name);
		free(head->content);
		free(head);
		head = next;
	}
}

void	free_cmd_tbls(t_cmd_tbl *cmd_tbls)
{
	t_cmd_tbl	*tmp;

	tmp = NULL;
	if (cmd_tbls == NULL)
		return ;
	while (cmd_tbls != NULL)
	{
		free_tokens(cmd_tbls->args);
		free_tokens(cmd_tbls->redirs);
		free_char_array(cmd_tbls->cmd_args);
		free(cmd_tbls->cmd);
		free(cmd_tbls->heredoc_name);
		tmp = cmd_tbls->next;
		free(cmd_tbls);
		cmd_tbls = tmp;
	}
}

void	free_at_exit(t_shell *shell)
{
	t_token	*token;

	if (shell->trimmed_prompt != NULL)
		free_cmd_tbls(shell->cmd_tbls);
	free_char_array(shell->cmd_paths);
	free(shell->terminal_prompt);
	free(shell->trimmed_prompt);
	free_char_array(shell->env);
	free_env(shell->env_head);
	free(shell->prev_prompt);
	free(shell->heredoc);
	free(shell->prompt);
	rl_clear_history();
}

void	free_at_child(t_shell *shell)
{
	t_token	*token;

	if (shell->trimmed_prompt != NULL)
		free_cmd_tbls(shell->cmd_tbls);
	free_char_array(shell->cmd_paths);
	free(shell->terminal_prompt);
	free_char_array(shell->env);
	free(shell->trimmed_prompt);
	free_env(shell->env_head);
	free(shell->prev_prompt);
	free(shell->heredoc);
	free(shell->prompt);
	rl_clear_history();
}
