/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harleyng <harleyng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 13:59:18 by harleyng          #+#    #+#             */
/*   Updated: 2025/06/03 00:50:44 by harleyng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include <termios.h>

typedef enum e_type
{
	WORD,
	HEREDOC,
	OUTPUT,
	APPEND,
	INPUT,
	UNKNOWN
}						t_type;

typedef struct s_token
{
	char			*content;
	struct s_token	*next;
	struct s_token	*prev;
	t_type			type;
}	t_token;

typedef struct s_cmd_tbl
{
	int					index;
	char				*cmd;
	char				**cmd_args;
	char				*heredoc_name;
	struct s_cmd_tbl	*next;
	t_token				*args;
	t_token				*redirs;
}	t_cmd_tbl;

typedef struct s_env
{
	char			*content;
	char			*var_name;
	struct s_env	*next;
}	t_env;

typedef struct s_shell
{
	int				envless;
	int				color_codes;
	int				exit_code;
	int				print;
	int				cmd_has_been_executed;
	int				std_fds[2];
	int				exec_on_pipe;
	int				should_expand;
	int				should_execute;
	int				expand_heredoc;
	char			*user_name;
	char			**cmd_paths;
	char			**env;
	char			*heredoc;
	char			*prev_prompt;
	char			*trimmed_prompt;
	char			*terminal_prompt;
	char			*prompt;
	struct termios	mirror_termios;
	t_env			*env_head;
	t_cmd_tbl		*cmd_tbls;
}	t_shell;

#endif