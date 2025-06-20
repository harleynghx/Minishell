/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liyu-her <liyu-her@student.42.kl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 13:59:13 by harleyng          #+#    #+#             */
/*   Updated: 2025/06/11 18:47:27 by liyu-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

// OWN HEADERS
# include "../libft/includes/libft.h"
# include "colors.h"
# include "defines.h"
# include "structs.h"

// STANDARD HEADERS
# include <dirent.h>
# include <errno.h>
# include <fcntl.h>
# include <limits.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <termios.h>
# include <unistd.h>

// READLINE
# if defined(__APPLE__)
#  include <readline/history.h>
#  include <readline/readline.h>
# else
#  include </usr/include/readline/history.h>
#  include </usr/include/readline/readline.h>
#  include <sys/wait.h>
# endif

extern int	g_ctrl_c;

// MAIN UTILS
int			cmd(t_shell *shell, char *str, int s);
bool		add_history_if(char *prompt, char *prev_prompt);

// SHELL_LOOP
int			*read_line(t_shell *shell);
void		shell_loop(t_shell *shell);
void		addhistory(t_shell *shell);
// bool		is_builtin(t_shell *shell);

// PROMPT
char		*curr_dir(t_shell *shell);
void		terminal_prompt(t_shell *shell);

// BUILTINS
bool		builtins(t_shell *shell, char *cmd, char **args);
void		call_echo(t_shell *shell, char *cmd, char **args);

// BUILTIN ENV
char		*get_path(char **env);
t_env		*init_env(char **env);
t_env		*init_env_node(char *str);
char		*get_full_env(t_env *env);
void		update_env(t_shell *shell);
void		print_env_vars(t_env *head);
char		**env_list_to_char(t_env *env);
int			get_env_list_size(t_env *head);
void		env(t_shell *shell, char **args);
void		add_back_env_node(t_env *head, t_env *new);
char		*get_env_value(char **env, const char *name);

// BUILTIN EXPORT
char		*get_variable(char *prompt);
void		print_export(t_shell *shell);
int			count_equal_sign(t_shell *shell);
char		*empty_content_allocate(char *content);
void		add_new_variable(t_shell *shell, char *str);
char		*get_env_content(char *full, char *var_name);
void		export(t_shell *shell, char *cmd, char **args);
void		export_new_variables(t_shell *shell, char **args);
void		do_not_export(t_shell *shell, char **args, int i);
bool		is_valid_export(t_shell *shell, char *args, int i);
void		replace_var_content(t_shell *shell, char *str, char *var);

// BUILTIN UNSET
bool		has_plus(char *str);
void		free_env_var(t_env *env);
bool		has_invalid_chars(char *str);
void		delete_env_var(t_env *head, t_env *del);
bool		unset_special(t_shell *shell, char **args);
t_env		*find_env_var(t_env *head, char *var_name);
void		unset_all_vars(t_shell *shell, char **args);
void		unset(t_shell *shell, char *cmd, char **args);

// BUILTIN PWD
void		pwd(t_shell *shell);

// BUILTIN EXIT
void		simple_exit(t_shell *shell);
void		exit_tma(t_shell *shell, char *cmd);
void		exit_code(t_shell *shell, char **args);
void		exit_code_on_pipe(t_shell *shell, char **args);
bool		is_exit_code_correct(t_shell *shell, char *args, int i);
void		exit_shell(t_shell *shell, char *cmd, char **args);
void		exit_error_msg(t_shell *shell, char *cmd, char *arg, int option);

// BUILTIN CD
void		cd_home(t_shell *shell);
void		cd_oldpwd(t_shell *shell);
bool		strcmp_2(char *str1, char *str2);
void		add_oldpwd_to_env(t_shell *shell);
int			nb_delimited_words(char *s, char c);
void		cd_oldpwd_fallback(t_shell *shell);
void		cd(t_shell *shell, char **args);
void		cd_tilde(t_shell *shell, char *folder_path);
void		cd_forward(t_shell *shell, char *folder_path);
void		update_pwd_and_oldpwd(t_shell *shell, char *old_pwd);
void		cd_back(t_shell *shell, char *dotdot, char *folder_path);

// BUILTIN ECHO
bool		is_in_dq(char *s, int i);
bool		space_filled_token(char *str);
bool		has_quote_in_string(char *str);
void		echo(t_shell *shell, char *cmd, char **args);
int			write_escapes(char *str, int escp_nb, int i);
void		print_without_quotes(char *str, int i, int k, int dq);

// INITIALIZE
void		init_shell(t_shell *shell, char **env);

// SIGNALS
void		signal_c(void);
void		signals_parent(void);
void		signal_ctrl_c_child(void);
void		signal_ctrl_c_parent(void);
void		signal_ctrl_backslash(void);
void		signal_backslash(void);
void		handle_sigint(int sig_num);
void		signal_ctrl_backslash_child(void);
void		signals(struct termios *mirror_termios);
void		signals_child(struct termios *mirror_termios);
void		handle_signals(struct termios *mirror_termios);
void		save_settings_and_remove_c(struct termios *mirror_termios);

// LEXER
bool		is_space(char c);
bool		is_operator(char c);
int			lexer(t_shell *shell);
bool		contains_triple_redirection(char *str);
bool		bad_pipe(t_shell *shell);
bool		has_wrong_pipe(char *str);
bool		redir_before(char *str, int i);
bool		wrong_operator_check(char *str);
bool		is_emptyline(t_shell *shll);
bool		count_quotes(char *s, int sq, int dq);
int			nb_esc_chars(char *str, int last_ind);
char		*ft_strdup2(char *str, int start, int end);

// PARSER
bool		parser(t_shell *shell);
bool		table_check(t_cmd_tbl *tables);
// PIPE TOKENS
int			count_pipes(char *str);
int			skip_quotes(char *str, int index);
char		**split_pipes(char *str, int start, int end, int index);
// COMMAND TABLE
// char		*rm_quotes(char *str);
void		init_cmd_args(t_cmd_tbl *tables);
void		cmd_to_lower_case(t_cmd_tbl *table);
// void		rm_quotes_table(t_cmd_tbl *table, t_shell *shell);
// void		rm_quotes_tokens(t_token *tokens, t_shell *shell);
t_cmd_tbl	*create_cmd_table(char **str_arr, t_shell *shell);
void		rm_quotes_tables(t_cmd_tbl *table, t_shell *shell);
t_token		*tokenize(char *str, t_token *token);
t_cmd_tbl	*new_cmd_table(void);
// INIT TABLE
t_token		*assign_cmd(t_cmd_tbl *cmd_tbl, t_token *token);
t_token		*assign_args(t_cmd_tbl *cmd_tbl, t_token *token);
t_token		*assign_redirs(t_cmd_tbl *cmd_tbl, t_token *token);
char		**get_cmd_args_from_token(char *cmd, t_token *token);
t_cmd_tbl	*init_cmd_table(t_cmd_tbl *cmd_tbls, t_token *tokens);
// CMD TABLE UTILS
bool		is_printable(char c);
t_cmd_tbl	*get_empty_cmd_table(void);
int			token_list_size(t_token *token);
t_cmd_tbl	*add_new_cmd_tbl(t_cmd_tbl *cmd_tbl, t_cmd_tbl *new);
// ADD TOKEN
t_token		*token_flag(char *str, int *i, int *old_i, t_token *token);
t_token		*token_word(char *str, int *i, int *old_i, t_token *token);
t_token		*token_quote(char *str, int *i, int *old_i, t_token *token);
t_token		*token_redir(char *str, int *i, int *old_i, t_token *tk);
// ADD TOKEN UTILS
t_token		*copy_token(t_token *token);
t_token		*get_new_token(char *str, t_type type);
t_token		*add_new_token2(t_token *tokens, t_token *new);
t_token		*add_new_token(t_token *lexer, char *str, t_type type);
// TOKEN UTILS
void		free_tokens(t_token *token);
bool		is_redirection(t_token *token);
t_type		get_redirection_type(char *str, int start, int end);

// EXPANDER
// char		*variable_doesnt_exist(void);
bool		dont_expand(char *str, int i);
char		*copy_variable(char *content);
// char		*return_exit_status(t_shell *shell);
bool		expander(char **str, t_shell *shell);
bool		has_dollar(char *str, t_shell *shell);
void		expand_table(t_cmd_tbl *table, t_shell *shell);
void		expand_tokens(t_token *tokens, t_shell *shell);
char		*expand_cmd(t_cmd_tbl *table, t_shell *shell);
void		expand_tables(t_cmd_tbl *tables, t_shell *shell);
// char		*replace_variable(char *variable, t_shell *shell);
char		*expand_dollars(char *doll_to_exp, t_shell *shell);
// bool		dont_expand_result(char *str, int i, int dq, int sq);
char		*type_to_expand(char *dollar_to_expand, t_shell *shell);
void		copy_dollar_from_string(char **dst, char **s, int index);
// void		extract_dollar(char **s, t_shell *sh, char **bef_doll, char **rest);

// EXECUTOR
int			table_size(t_cmd_tbl *table);
void		execute(t_shell *shell, t_cmd_tbl *table);
void		exec_without_pipes(t_cmd_tbl *table, t_shell *shell);
void		execute_command(t_cmd_tbl *table, t_shell *shell);
// COMMAND HANDLING
char		*extract_path(t_shell *shell, char *command);
void		invalid_command(t_shell *shell, char *command);
// PATH CHECK
int			path_check(char *cmd_path, t_shell *shell);
// HANDLE REDIRECTIONS
bool		is_good_redirection(t_token *token);
void		handle_redirections(t_shell *shell, t_cmd_tbl *table);
int			open_file(t_type type, char *file_name, t_shell *shell);
bool		has_wrong_redir(t_shell *shell, t_token *token, t_cmd_tbl *table);
// HEREDOC EXEC
char		*stop_word(char *str, t_shell *shell);
void		handle_heredocs(t_cmd_tbl *cmd_tbl, t_shell *shell);
char		*heredoc(t_cmd_tbl *cmd_tbl, char *stop_word, t_shell *shell);
bool		heredocs_break(t_shell *shell, char *input, char *s_w);

// OPEN HEREDOC
int			open_heredoc(t_cmd_tbl *table, t_shell *shell, t_token *token);
// PIPELINE
// EXEC ONLY HEREDOC
bool		invalid_redir_and_initiate_heredocs(t_cmd_tbl *table,
				t_shell *shell);
// EXEC PIPES
void		exec_pipes(t_cmd_tbl *table, t_shell *shell);
// EXEC UTILS
void		child_exit(t_shell *shell);
void		reset_io_streams(t_shell *shell);
char		**duplicate_string_array(char **array);
void		clear_and_exit(t_shell *shell, char *cmd_path, t_cmd_tbl *table);
void		waitpid_to_get_exit_status(pid_t pid, t_shell *shell, int *status);

// GENERAL UTILS
int			ft_isupper(char c);
bool		unclosed_quotes(char *str);
int			skip_spaces(char *str, int index);
bool		convert_to_lower(char *str, int until);

// ERROR HANDLING
void		ft_arg(int argc);
bool		syntax_error(char c);
bool		syntax_error_newline(void);

// CLEANUP TOOLS
void		free_env(t_env *head);
void		free_at_exit(t_shell *shell);
void		free_char_array(char **array);
void		free_cmd_tbls(t_cmd_tbl *cmd_tbls);

// what does the philosopher pigeon say?
// TO BE OR NOT TO BE

#endif