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
# include <signal.h>

typedef struct s_cmd
{
    char *input_file;     // Для "<"
    int pos_input;        // Позиция для приоритета входного редиректа
    char *here_doc_file;  // Для "<<"
    int pos_here_doc;     // Позиция для приоритета here_doc
    char *cmd;            // Основная команда (например, "echo")
    char **cmd_arg;        // Аргументы команды (например, "hello world")
    char *output_file;    // Для ">"
    char *append_file;    // Для ">>"
    int pos_output;       // Позиция для приоритета вывода
    int pos_append;       // Позиция для приоритета append
} t_cmd;

typedef struct s_data
{
    char **envp;      // Переменные окружения
    t_cmd **cmd;      // Массив структур команд
    int nb_pipe;      // Количество пайпов
    int prev_pipe;    // Флаг пайпа для предыдущей команды
    int i;            //Индекс текущей команды
    int here_doc_pfd; // канал для чтения данных принятых here_doc ,                                       //add
    int flag_pipe;    //Что бы определить если заполненый пайп                                      //add
    int exit_status;  //Сохраняем индекс последнего процесса запущеной команды

    int heredoc_interrupted;
} t_data;

extern int g_pid;

void		parse_pipeline(t_data *command, char *input);
// void	execute_pipeline(char ***commands, char **envp);
void		free_parsed_commands(t_data **commands);
char		*find_command(char *cmd, char **envp);
void		free_split(char **args);
void		error_exit(const char *message);
//void		launch_here_doc(char **argv, int pipefd[2]);
//void		ft_redirection_in(char *input_file);
//void		ft_redirection_out_append(char *output_file);
//void		ft_redirection_out(char *output_file);
//void		execute_pipeline(t_data *commands);
char		**ft_split_quotes(const char *input);
void		free_structure(t_data *command);

int         ft_strncmp(const char *s1, const char *s2, size_t n);
char        *get_next_line(int fd);
char        *ft_strjoin(char const *s1, char const *s2);
char        **ft_split(char const *s, char c);
int         ft_strlen(const char *str);
size_t      ft_strlcpy(char *dest, const char *src, size_t size);
char        *ft_strnstr(const char *big, const char *little, size_t len);
char        *ft_strdup(const char *s);
char        *ft_envp_cherch(char *cmd, char **envp);
char        *ft_creat_path(char **strs, char *cmd);
void        ft_add_cmd(char **strs, char *cmd);
void        ft_add_symb(char **strs);

void		choice_execution(t_data *data);                             //Здесь будет происходить выбор между нашими командами и системными
void		execution_cmd(t_data *data);                                //Функция где создаются дочерние процессы и пайпы
void		ft_launch_cmd(t_data *data, int pipefd[2]);                 //Запускает исполнение системной команды + редирекции
void	    wait_processes(t_data *data);                               //Ожидание последнего дочернего процесса + сохраняем статус последнего 
char        **join_arg(t_data *data);                                   //Объединяем имя команды , аргумент , + NULL требуется для execve
//void		ft_launch_here_doc(t_data *data);
void		execution_here_doc(t_data *data);                           //Если есть here_doc то это функция которая его исполняет

void        redirection_input(t_data *data, int pipefd[2]);             //Функция определяет какой из 4 вариантов input нужно задействовать для текущей команды
void        redirection_output(t_data *data, int pipefd[2]);            //Функция определяет какой из 4 вариантов output нужно задействовать для текущей команды

void        ft_redirection_in(t_data *data, int pipefd[2]);             //Переадресация из файла в команду
void        ft_redirection_here_doc(t_data *data, int pipefd[2]);       //Переадресация из here_doc в команду
void        ft_redirection_pipe(t_data *data, int pipefd[2]);           //Переадресация из пайпа в команду
void        ft_redirection_out_cmd(t_data *data, int pipefd[2]);        //Переадресация из команды в файл / 2 варианта файла
void        ft_redirection_out_pipe(t_data *data, int pipefd[2]);       //Переадресация из команды в пайп

/*Блок для корректного выхода из процесса из за ошибок */
void	free_fault_execve(char *cmd, t_data *data);
void		ft_free_strs(char **strs);
void		ft_error_exit(int nb);
void		free_pipe(int fd);
void	    error_join_arg(t_data *data);
void		error_empty_cmd(t_data *data);
void		free_error_cmd(t_data *data);
void	    error_open_outfile(int flag , t_data *data);


void	free_data(t_data *data);

void    handle_sigint(int sig);

void	check_builtin(t_data *data);
void	echo(t_data *data);
int	    check_option_n(char *arg);
void	close_input(t_data *data);
#endif
