/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liyu-her <liyu-her@student.42kl.edy.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 13:59:04 by harleyng          #+#    #+#             */
/*   Updated: 2025/06/10 23:22:39 by liyu-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# define TRUE 1
# define FALSE 0
# define FAIL 999

# define SHELL "minishell: "

// OPERATORS
# define SQUOTE 39
# define DQUOTE 34
# define PIPE "|"
# define OPERATORS "|><"
# define REDIRECTIONS "><"
# define SPACES " \t\n\v\r\f"

// OPEN
# define GIVE_PERM_WTH_RW 0644

// TMP HEREDOC FILES
# define TMP_S "/tmp/heredoc"
# define TMP_E ".XXXXXX"

// HEREDOC TYPE
# define HD_PIPE "\033[1;34mpipe heredoc> \033[0m"
# define HERE_DOC "\033[1;34mheredoc> \033[0m"

// PARSE ERROR
# define SYNTAX_ERROR "syntax error near unexpected token"
# define SYNTAX_ERROR_NEWLINE "syntax error near unexpected token `newline'"

// STDERRORS
# define FORK_ERROR "fork faild, no child has been created, we used protection"
# define PIPE_ERROR "pipe failed"
# define MALLOC_FAIL "memory allocation failed"
# define CMD_NOT_FND "command not found"
# define INVALID_CMD "command not found"
# define NAR "numeric argument required"
# define NVI "not a valid identifier"
# define TMA "too many arguments"
# define HOMELESS "HOME not set"
# define PWNED "OLDPWD not set"
# define ISDIR "is a directory"
# define DNE "does not exist."
# define C_D "/usr/bin/cd"

#endif