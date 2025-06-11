/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liyu-her <liyu-her@student.42.kl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 14:16:38 by harleyng          #+#    #+#             */
/*   Updated: 2025/06/11 15:29:04 by liyu-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

/*
don't try to print content if it's empty
print all the variables in normal mode
don't print term in no env mode
*/
void	env(t_shell *shell, char **args)
{
	t_env	*curr;

	if (args[1])
	{
		if (shell->print)
			p_err("env: '%s': No such file or directory\n", args[1]);
		shell->exit_code = 127;
		return ;
	}
	if (!shell->print)
		return ;
	shell->exit_code = 0;
	curr = shell->env_head;
	while (curr)
	{
		if (curr->content)
		{
			if (curr->content[0] == ' ' && curr->content[1] == '\0')
				printf("%s=\n", curr->var_name);
			else
				printf("%s=%s\n", curr->var_name, curr->content);
		}
		curr = curr->next;
	}
}

char	*get_full_env(t_env *env)
{
	char	*tmp;
	char	*result;

	tmp = ft_nm_strjoin(env->var_name, "=");
	if (env->content != NULL)
	{
		result = ft_nm_strjoin(tmp, env->content);
		free(tmp);
	}
	else
		return (tmp);
	return (result);
}

int	get_env_list_size(t_env *head)
{
	t_env	*curr;
	int		i;

	i = 0;
	curr = head;
	while (curr != NULL)
	{
		curr = curr->next;
		i++;
	}
	return (i);
}

char	**env_list_to_char(t_env *env)
{
	char	**result;
	int		size;
	int		i;

	i = 0;
	size = get_env_list_size(env);
	result = malloc(sizeof(char *) * (size + 1));
	result[size] = NULL;
	while (env != NULL && i < size)
	{
		result[i] = get_full_env(env);
		env = env->next;
		i++;
	}
	return (result);
}

char	*get_env_value(char **env, const char *name)
{
	int	i;
	int	len;

	if (!env || !name)
		return (NULL);
	len = ft_strlen(name);
	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], name, len) == 0 && env[i][len] == '=')
			return (env[i] + len + 1);
		i++;
	}
	return (NULL);
}
