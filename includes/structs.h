/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liyu-her <liyu-her@student.42.kl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 13:59:18 by harleyng          #+#    #+#             */
/*   Updated: 2025/05/21 12:06:11 by liyu-her         ###   ########.fr       */
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
}	t_type;

typedef struct s_token
{
	t_type			type;
	struct s_token	*next;
	struct s_token	*prev;
	char			*content;
}	t_token;

typedef struct s_cmd_tbl
{
	char				*cmd;
	t_token				*args;
	struct s_cmd_tbl	*next;
	int					index;
	t_token				*redirs;
	char				**cmd_args;
	char				*heredoc_name;
}	t_cmd_tbl;

typedef struct s_env
{
	struct s_env	*next;
	char			*content;
	char			*var_name;
}	t_env;

typedef struct s_shell
{
	int				envless;
	int				color_codes;
	t_env			*env_head;
	char			*user_name;
	char			**cmd_paths;
	char			**env;
	int				exit_code;
	int				print;
	char			*heredoc;
	t_cmd_tbl		*cmd_tbls;
	char			*prev_prompt;
	char			*trimmed_prompt;
	char			*terminal_prompt;
	int				cmd_has_been_executed;
	char			*prompt;
	int				std_fds[2];
	int				exec_on_pipe;
	int				should_expand;
	int				should_execute;
	int				expand_heredoc;
	struct termios	mirror_termios;
}	t_shell;

#endif