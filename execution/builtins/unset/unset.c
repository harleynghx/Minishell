/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harleyng <harleyng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 14:17:26 by harleyng          #+#    #+#             */
/*   Updated: 2025/06/07 22:48:59 by harleyng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	unset(t_shell *shell, char *cmd, char **args)
{
	if (args[1] == NULL)
		return ;
	if (unset_special(shell, args) == TRUE)
		return ;
	else
		unset_all_vars(shell, args);
}

void	unset_all_vars(t_shell *shell, char **args)
{
	int		i;
	t_env	*env;

	i = 1;
	while (args[i] != NULL)
	{
		env = find_env_var(shell->env_head, args[i]);
		if (env != NULL)
		{
			shell->exit_code = 0;
			delete_env_var(shell->env_head, env);
			env = NULL;
		}
		else if (args[i][0] == '-')
			shell->exit_code = 2;
		else if (ft_pf_strchr(args[i], '=') || ft_pf_strchr(args[i], '\\')
			|| has_invalid_chars(args[i]) == TRUE)
		{
			shell->exit_code = 1;
			if (shell->print == TRUE)
				p_err("%s%s: `%s': %s\n", SHELL, args[0], args[i], NVI);
		}
		i++;
	}
}

t_env	*find_env_var(t_env *head, char *var_name)
{
	t_env	*curr;
	size_t	name_len;

	if (!var_name)
		return (NULL);
	name_len = ft_strlen(var_name);
	curr = head;
	while (curr != NULL)
	{
		if (curr->var_name
			&& ft_strncmp(curr->var_name, var_name, name_len) == 0
			&& ft_strlen(curr->var_name) == name_len)
			return (curr);
		curr = curr->next;
	}
	return (NULL);
}

void	delete_env_var(t_env *head, t_env *del)
{
	t_env	*tmp;
	t_env	*curr;

	curr = head;
	while (curr != NULL)
	{
		if (curr->next == del)
		{
			tmp = del->next;
			curr->next = tmp;
			free_env_var(del);
			return ;
		}
		curr = curr->next;
	}
}

void	free_env_var(t_env *env)
{
	free(env->var_name);
	free(env->content);
	free(env);
}
