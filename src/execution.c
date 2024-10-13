#include "../include/minishell.h"

// Function to execute a single command with redirection and pipe handling
void execute_command(t_command *cmd, char **envp, int pipefd[2])
{
    if (cmd->here_doc) {
        // Handle here_doc redirection
        launch_here_doc(cmd->args, pipefd);
    } 
    else if (cmd->input_file) {
        // Handle input redirection <
        ft_redirection_in(cmd->input_file);
    } 
    else if (cmd->output_file) {
        if (cmd->append) {
            // Handle output append >>
            ft_redirection_out_append(cmd->output_file);
        } else {
            // Handle output redirection >
            ft_redirection_out(cmd->output_file);
        }
    }
    
    // Execute the command normally
    char *cmd_path = find_command(cmd->args[0], envp);
    if (!cmd_path) {
        ft_putstr_fd("Command not found\n", 2);
        exit(127);
    }
    execve(cmd_path, cmd->args, envp);
    perror("execve");
    free(cmd_path);
    exit(EXIT_FAILURE);
}


// Main function to handle pipeline execution with pipes and redirections
void execute_pipeline(t_command *commands, char **envp)
{
    int pipefd[2];
    int prev_pipe = -1;
    int i = 0;

    while (commands->args[i])
    {
        // Создаем пайп только если это не последняя команда
        if (commands->args[i+1] != NULL)
        {
            if (pipe(pipefd) == -1)  // Убедитесь, что pipe успешно создан
                error_exit("pipe error");
        }
        else
        {
            // Инициализируем pipefd[0] и pipefd[1], если пайп не создается
            pipefd[0] = -1;
            pipefd[1] = -1;
        }

        pid_t pid = fork();
        if (pid == -1)
            error_exit("fork error");

        if (pid == 0) // Дочерний процесс
        {
            if (prev_pipe != -1) {
                dup2(prev_pipe, STDIN_FILENO);  // Используем вывод предыдущей команды как ввод
                close(prev_pipe);  // Закрываем старый файловый дескриптор только после использования
            }
            if (commands->args[i+1] != NULL) {
                dup2(pipefd[1], STDOUT_FILENO);  // Перенаправляем вывод на следующую команду
                close(pipefd[1]);  // Закрываем только дескриптор записи
            }
            if (pipefd[0] != -1) {
                close(pipefd[0]);  // Закрываем дескриптор чтения, если пайп был создан
            }

            execute_command(commands, envp, pipefd);  // Выполняем команду
        }
        else  // Родительский процесс
        {
            if (pipefd[1] != -1) {
                close(pipefd[1]);  // Закрываем дескриптор записи в родительском процессе
            }
            if (prev_pipe != -1)
                close(prev_pipe);  // Закрываем предыдущий дескриптор чтения, если он был
            prev_pipe = pipefd[0];  // Обновляем дескриптор для следующего процесса
        }
        i++;
    }

    // Ожидание завершения всех дочерних процессов
    while (wait(NULL) > 0);
}
/*
pid_t	create_fork(void)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		error_exit("fork");
	return (pid);
}

static void	execute_command(char **command, char **envp)
{
	char	*cmd_path;

	cmd_path = find_command(command[0], envp);
	if (!cmd_path)
	{
		ft_putstr_fd("Command not found\n", 2);
		exit(127);
	}
	execve(cmd_path, command, envp);
	perror("execve");
	free(cmd_path);
	exit(EXIT_FAILURE);
}

static void	launch_process(int fd_in, int pipefd[2], char **cmd, char **envp)
{
	pid_t	pid;

	pid = create_fork();
	if (pid == 0)
	{
		if (fd_in != 0)
		{
			dup2(fd_in, 0);
			close(fd_in);
		}
		if (pipefd[1] != 0)
		{
			dup2(pipefd[1], 1);
			close(pipefd[1]);
		}
		if (pipefd[0] != 0)
			close(pipefd[0]);
		execute_command(cmd, envp);
		exit(EXIT_SUCCESS);
	}
	else
	{
		if (pipefd[1] != 0)
			close(pipefd[1]);
	}
}

void	wait_for_processes(int *status)
{
	while (waitpid(-1, status, 0) > 0)
		;
}

void	close_pipes(int *fd_in, int pipefd[2])
{
	if (pipefd[1] != 0)
		close(pipefd[1]);
	if (*fd_in != 0)
		close(*fd_in);
	*fd_in = pipefd[0];
}

void	pipe_creation(int has_next, int pipefd[2])
{
	if (has_next)
	{
		if (pipe(pipefd) == -1)
		{
			perror("pipe");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		pipefd[0] = 0;
		pipefd[1] = 0;
	}
}

void	execute_pipeline(char ***commands, char **envp)
{
	int	pipefd[2];
	int	fd_in;
	int	i;
	int	status;

	fd_in = 0;
	i = 0;
	while (commands[i])
	{
		pipe_creation(commands[i + 1] != NULL, pipefd);
		launch_process(fd_in, pipefd, commands[i], envp);
		close_pipes(&fd_in, pipefd);
		i++;
	}
	while (waitpid(-1, &status, 0) > 0)
		;
	if (fd_in != 0)
		close(fd_in);
} */

/*void	execute_pipeline(char ***commands, char **envp)
{
	int	pipefd[2];
	int	fd_in;
	int	i;
	int	status;

	fd_in = 0;
	i = 0;
	while (commands[i])
	{
		if (commands[i + 1] != NULL)
		{
			if (pipe(pipefd) == -1)
			{
				perror("pipe");
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			pipefd[0] = 0;
			pipefd[1] = 0;
		}
		launch_process(fd_in, pipefd, commands[i], envp);
		if (pipefd[1] != 0)
			close(pipefd[1]);
		if (fd_in != 0)
			close(fd_in);
		fd_in = pipefd[0];
		i++;
	}
	while (waitpid(-1, &status, 0) > 0)
		;
	if (fd_in != 0)
		close(fd_in);
}
*/
