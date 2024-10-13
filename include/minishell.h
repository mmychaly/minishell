#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include <readline/history.h>
# include <readline/readline.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_command
{
	char **args;       // Массив аргументов команды
	char *input_file;  // Файл для оператора <
	char *output_file; // Файл для операторов > и >>
	int append;        // Флаг для оператора >>
	int here_doc;      // Флаг для оператора <<
	int is_pipe;       // Флаг для пайпа
}			t_command;

t_command	*parse_pipeline(char *input);
// void	execute_pipeline(char ***commands, char **envp);
void		free_parsed_commands(t_command **commands);
t_command	*parse_input(char *input);
char		*find_command(char *cmd, char **envp);
void		free_split(char **args);
void		error_exit(const char *message);
void		launch_here_doc(char **argv, int pipefd[2]);
void		ft_redirection_in(char *input_file);
void		ft_redirection_out_append(char *output_file);
void		ft_redirection_out(char *output_file);
void		execute_pipeline(t_command *commands, char **envp);

#endif
