/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artemii <artemii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 15:23:52 by mmychaly          #+#    #+#             */
/*   Updated: 2024/12/01 17:44:17 by artemii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include <readline/history.h>
# include <readline/readline.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <unistd.h>
# include <signal.h>
# include <limits.h>

typedef struct s_cmd
{
	char	*input_file;
	int		pos_input;
	char	*here_doc_file;
	int		pos_here_doc;
	char	*cmd;
	char	**cmd_arg;
	char	*output_file;
	char	*append_file;
	int		pos_output;
	int		pos_append;
	int		here_doc_pfd;
	char	**output_files;
	char	**append_files;
	char	**here_doc_files;
	char	**input_files;
	int		error_code;
	int		agr_idx;
	int		rd_idx;
}	t_cmd;

typedef struct s_data
{
	char	**envp;
	t_cmd	**cmd;
	int		nb_pipe;
	int		prev_pipe;
	int		i;
	int		flag_pipe;
	int		exit_status;
	int		heredoc_interrupted;
	int		back_in_main;
	char	*user_input;
	int		builtin_cmd;
	int		display_builtin_cmd;
	int		pipefd[2];
	int		std_out;
	int		free_target_dir;
}	t_data;

extern int	g_pid;

void	parse_pipeline(t_data *command, char *input);
void	free_parsed_commands(t_data **commands);
char	*find_command(char *cmd, char **envp);
void	free_split(char **args);
void	error_exit(const char *message);
char	**ft_split_quotes(const char *input, t_data *data);
void	free_structure(t_data *command);
void	free_cmd_files(t_cmd *cmd);
void	free_cmd_resources(t_cmd *cmd);
void	free_data_cmd(t_data *data);
void	free_all_data(t_data *data);
char	*handle_quotes(const char *str, int *i, t_data *data, char *result);
char	*merge_tokens(char *first, char *second);
char	*extract_quoted_token(const char *str, int *i, char quote_char);
void	skip_spaces(const char *str, int *i);
int		validate_quotes(const char *input);
char	**realloc_array(char **array, char *new_element);
void	handle_redir_file(t_cmd *cmd, char *token,
			int *redir_position, int redir_type);
int	handle_redirection(t_cmd *cmd, char *redir, char *after,
		int *redir_pos);
void	handle_command_args(t_cmd *cmd, char **tokens, int *i);
void	handle_here_docs(t_cmd *cmd, t_data *data);
char	*replace_env_var(char *input, t_data *data);
char	*replace_substring(char *str, int start, int end, char *replacement);
void	unset_var(t_data *data, char *key);
void	export_var(t_data *data, const char *input);
void	print_env(t_data *data);
void	cd(t_data *data, char *args);
char	*get_env_value(char *name, t_data *data);
int		update_or_add_var(t_data *data, char *new_var, char *key);
void	update_shlvl(t_data *data);
char	**copy_envp(char **envp);
char	*handle_no_argument(t_data *data, char *old_pwd);
char	*handle_dash_argument(t_data *data, char *old_pwd);
char	*handle_tilde_argument(t_data *data, char *arg,
			char *old_pwd, int *free_target_dir);
int		change_and_update_env(t_data *data, char *target_dir, char *old_pwd);
int		change_directory(t_data *data, char *target_dir);
int		update_environment(t_data *data, char *old_pwd);
void	cd_exit(t_data *data, int status, char *message, char *to_free);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*get_next_line(int fd);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);
int		ft_strlen(const char *str);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strdup(const char *s);
char	*ft_envp_cherch(char *cmd, char **envp);
char	*ft_creat_path(char **strs, char *cmd);
void	ft_add_cmd(char **strs, char *cmd);
void	ft_add_symb(char **strs);
void	choice_execution(t_data *data);
void	execution_cmd(t_data *data);
void	manage_fd(t_data *data, int pid);
void	ft_launch_cmd(t_data *data);
void	check_file_args(t_data *data);
void	wait_processes(t_data *data);
void	execution_here_doc(t_cmd *cmd, char *here_doc_file, t_data *data);
void	read_line_here_doc(char *here_doc_file, int pipefd);
void	redirection(t_data *data);
void	ft_redirection_in(t_data *data);
void	ft_redirection_here_doc(t_data *data);
void	manage_fd_redirection_input(t_data *data, int flag_heredoc);
int		check_input_files(t_data *data, int flag_heredoc);
void	redirection_input_stdin(t_data *data, int fd_in);
void	redirection_here_doc_stdin(t_data *data);
void	ft_redirection_pipe(t_data *data);
void	ft_redirection_out_cmd(t_data *data);
void	manage_fd_redirection_output(t_data *data);
int		check_output_files(t_data *data);
int		check_append_files(t_data *data);
int		redirection_output_stdout(t_data *data, int fd_out);
int		check_files(t_data *data, int flag);
int		redirection_output(t_data *data, int fd_out);
void	ft_redirection_out_pipe(t_data *data);
void	reset_data_flags(t_data *data);
void	handle_pid_status(t_data *data, int *exit_status);
void	free_fault_execve(char *cmd, t_data *data);
void	ft_free_strs(char **strs);
void	ft_error_exit(int nb);
void	free_pipe(int fd);
void	error_join_arg(t_data *data);
void	error_empty_cmd(t_data *data);
void	free_error_cmd(t_data *data);
void	error_open_outfile(int flag, t_data *data);
void	free_data(t_data *data);

void	handle_sigint(int sig);
void	handle_signals(void);

void	execute_builtin_command(t_data *data);
void	check_builtin_command(t_data *data);
void	redirection_builtin_command(t_data *data);
void	launch_func_builtin(t_data *data);
void	remove_stdout(t_data *data);
void	echo(t_data *data);
int		check_option_n(char *arg);
void	display_str(t_data *data, int i_2, int n);
void	exit_total(t_data *data);
void	check_isdigit(t_data *data);
int		ft_atoi_mod(const char *nptr);
void	pwd(t_data *data);
void	close_input(t_data *data);
void	free_all_data(t_data *data);
void	free_data_cmd(t_data *data);
void	sigint_heredoc(t_data *data, int pipefd[2], int in);
int		exit_cmds_builtin(t_data *data, char *error,
			int status, char *most_by_free);
void	close_here_doc_pfd(int fd);
void	exit_eof(char *lim);
void	exit_only_child(t_data *data, int status);
void	error_fork(t_data *data);
int		exit_open(t_data *data, int fd_out);
void	check_dir(t_data *data, char *cmd);
char	*replace_substring(char *str, int start, int end, char *replacement);
char	*check_result(t_data *data, char *result, int i);
char	*extract_var_name(const char *str);
int		env_var_exists(const char *name, t_data *data);
char	*get_env_value(char *name, t_data *data);
char	*process_variable(char *result, int *i, t_data *data);
char	*replace_env_var(char *input, t_data *data);
void	take_dir(t_data *data, char *arg, char *old_pwd, char *target_dir);
int		check_new_dir(t_data *data, char *old_pwd, char	*target_dir);
void	cd(t_data *data, char *arg);


void	process_redirection_token(t_cmd *cmd, char *token, int *i,
		char **tokens);
void	free_temp_redir(char *before, char *redir, char *after);
void	handle_missing_after(t_cmd *cmd, char *before, char *redir, char *after);
void	handle_before_token(t_cmd *cmd, char *before);
void	update_redirection(char **target_file, char ***file_array, char *token);
void	handle_redir_token(t_cmd *cmd, char *after, char *redir);

#endif
