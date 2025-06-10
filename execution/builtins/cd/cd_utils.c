/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harleyng <harleyng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 14:01:38 by harleyng          #+#    #+#             */
/*   Updated: 2025/06/09 19:29:36 by harleyng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	nb_delimited_words(char *s, char c)
{
	int	boo;
	int	count;
	int	index;

	boo = 0;
	index = 0;
	count = 0;
	while (s[index] != '\0')
	{
		if (s[index] == c)
			boo = 0;
		else if (s[index] != c && boo == 0)
		{
			count++;
			boo = -1;
		}
		index++;
	}
	return (count);
}

bool	strcmp_2(char *str1, char *str2)
{
	int	i;

	i = 0;
	if (str1 == NULL || str2 == NULL)
		return (FALSE);
	if (ft_strlen(str1) != ft_strlen(str2))
		return (FALSE);
	while (str1[i] != '\0' || str2[i] != '\0')
	{
		if (str1[i] != str2[i])
			return (FALSE);
		i++;
	}
	return (TRUE);
}

void	update_pwd_and_oldpwd(t_shell *shell, char *old_pwd)
{
	char	*new_pwd;
	char	*pwd_entry;
	char	*oldpwd_entry;
	int		save_code;

	add_oldpwd_to_env(shell);
	save_code = shell->exit_code;
	new_pwd = getcwd(NULL, 0);
	if (!new_pwd)
		return ;
	pwd_entry = ft_nm_strjoin("PWD=", new_pwd);
	oldpwd_entry = ft_nm_strjoin("OLDPWD=", old_pwd);
	if (pwd_entry && oldpwd_entry)
	{
		replace_var_content(shell, oldpwd_entry, "OLDPWD");
		replace_var_content(shell, pwd_entry, "PWD");
	}
	shell->exit_code = save_code;
	free(new_pwd);
	free(pwd_entry);
	free(oldpwd_entry);
}

void	add_oldpwd_to_env(t_shell *shell)
{
	if (find_env_var(shell->env_head, "OLDPWD") == 0)
		add_new_variable(shell, "OLDPWD");
}

void	cd_oldpwd_fallback(t_shell *shell)
{
	if (shell->print == TRUE)
		p_err("%scd: %s\n", SHELL, PWNED);
	shell->exit_code = 1;
}
