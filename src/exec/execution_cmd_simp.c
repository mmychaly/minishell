/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_cmd_simp.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmychaly <mmychaly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 00:53:45 by mmychaly          #+#    #+#             */
/*   Updated: 2024/11/13 09:24:04 by mmychaly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"


void	execution_here_doc(t_data *data)
{
	char	*line;
	int		pipefd[2];
	int		in;

	line = NULL;
	g_pid = -5; //Показываем обработчику SIGINT что мы в HEREDOC
	data->heredoc_interrupted = 0; //Костыль который помогает понять что мы выйшли из функции по ошибке//Сигналу
	if (pipe(pipefd) == -1)
	{
		perror("ERROR in here doc");
		return ;
	}
	in = dup(0);//Дублируем стандратный ввод в переменную так как мы в процессе получения сигнала закроем fd стандратного входа и нам его нужно будет востановить потом
	write(1, "> ", 2);
	line = get_next_line(0);
	while (line != NULL)
	{
		
		if (ft_strncmp(data->cmd[data->i]->here_doc_file, line, ft_strlen(line) - 1) == 0 && line[0] != '\n')
		{
			free(line);
			break ;
		}
		write(pipefd[1], line, ft_strlen(line));
		free(line);
		write(1, "> ", 2);
		line = get_next_line(0);
	}
	if (g_pid == -10) //Если мы вышли из цикла из за обработчика сигнала SIGINT то входим в это условие 
	{
		close(pipefd[1]); //Закрываем канал записи
		free_pipe(pipefd[0]); //Освобождаем пайп если что то записали в него
        close(pipefd[0]); // Закрываем канал чтения
		if (dup2(in, 0) == -1) //Востанавливаем стандартный вход
		{
        	perror("dup2 failed");
        	close(in);
       		exit(1);
    	}
		close(in); //Закрываем fd который времено хранил указатель на стандартный вход
		g_pid = -1; //Возвращаем в глобальную переменную значение которое указывает что мы в родительском процессе
		data->exit_status = 130; //Обнавляем статус закрытия команды
        return; 
    }
	close(pipefd[1]);
	close(in);
	data->here_doc_pfd = pipefd[0];//А не должен ли я закрыть этот канал pipefd[0] ?
	data->heredoc_interrupted = 1; //Значение указывает что мы корректно отработали в here doc и можно переходить к запуску дочерних процессов
	g_pid = -1;
}

void	redirection_input(t_data *data, int pipefd[2])
{
	if (data->cmd[data->i]->pos_here_doc > data->cmd[data->i]->pos_input)
		ft_redirection_here_doc(data, pipefd);
	else if (data->cmd[data->i]->pos_here_doc < data->cmd[data->i]->pos_input)
		ft_redirection_in(data, pipefd);
	else if (data->cmd[data->i]->here_doc_file == NULL && data->cmd[data->i]->input_file == NULL && data->prev_pipe != -1)
		ft_redirection_pipe(data, pipefd);
	else
	{
		if (data->i != data->nb_pipe)
    		close(pipefd[0]);
	}
}

void	redirection_output(t_data *data, int pipefd[2])
{
	if (data->cmd[data->i]->output_file != NULL || data->cmd[data->i]->append_file != NULL)
		ft_redirection_out_cmd(data, pipefd);
	else if (data->cmd[data->i]->output_file == NULL && data->cmd[data->i]->append_file == NULL && data->i != data->nb_pipe)
		ft_redirection_out_pipe(data, pipefd);
	else
	{
		if (data->i != data->nb_pipe)
    		close(pipefd[1]);
	}
}

void	ft_launch_cmd(t_data *data, int pipefd[2])
{
	char	*cmd;

	redirection_input(data, pipefd);
	redirection_output(data, pipefd);
	execute_builtin_command(data);
	if (data->cmd[data->i]->cmd_arg[1] != NULL)
	{
		if (access(data->cmd[data->i]->cmd_arg[1], F_OK) == 0)
		{
			if (data->flag_pipe == 1)
				free_pipe(0);
       		if (access(data->cmd[data->i]->cmd_arg[1], R_OK) == -1)
      	  	{
				write(2, "Error file in arg :Permission denied\n", 37);
				free_all_data(data);
				exit(1);
			}
   		}
	}
	if (data->cmd[data->i]->cmd[0] == '\0')
		error_empty_cmd(data);
	if (access(data->cmd[data->i]->cmd, F_OK | X_OK) == 0)
		cmd = ft_strdup(data->cmd[data->i]->cmd);
	else
		cmd = ft_envp_cherch(data->cmd[data->i]->cmd, data->envp);
	if (cmd == NULL)
		free_error_cmd(data);
	if (execve(cmd, data->cmd[data->i]->cmd_arg, data->envp) == -1)
		free_fault_execve(cmd, data);
}

void	execution_cmd(t_data *data)
{
	int pid;
	int	pipefd[2];

	data->prev_pipe = -1;
	data->here_doc_pfd = -1;
	data->i = 0;
	data->flag_pipe = 0;
	if (data->nb_pipe == 0)
	{
		execute_builtin_command(data);
		if (data->back_in_main == 1)
			return ;
	}
	while (data->i <= data->nb_pipe)
	{	
		if (data->cmd[data->i]->here_doc_file != NULL)
		{
			execution_here_doc(data);
			if (data->heredoc_interrupted != 1)//Если значение 0 значит работа here doc завершилась не корректно и нам нужно обратно в главный цикл
				return ;
			if (data->here_doc_pfd == -1)
				write(2, "ERROR in here_doc\n", 18);
		}
		if (data->i != data->nb_pipe && pipe(pipefd) == -1)
		{
			write(2, "ERROR: pipe",11);
			data->exit_status = 1;
			return ;
		}
		pid = fork();
		if (pid == -1)
		{
			write(2,"ERROR: fork", 11);
			data->exit_status = 1;
			return ;
		}
		if (pid == 0)
		{
			signal(SIGQUIT, SIG_DFL); //Функция которая обрабатывает сигнал ctrl '\' . В дочернем процессе ,выходит из процесса
			ft_launch_cmd(data, pipefd);
		}
		else
			g_pid = pid;//После создания дочернего процесса , находясь в родительском помещаем в глобальную переменную pid дочернего процесса
		if (data->here_doc_pfd != -1 )
		{
			close(data->here_doc_pfd);
			data->here_doc_pfd = -1;
		}
		data->flag_pipe = 0;
		if (data->prev_pipe != -1)
			close(data->prev_pipe);
		if (data->i != data->nb_pipe)
			close(pipefd[1]);
		if (data->i == data->nb_pipe)
			data->prev_pipe = pid;
		else
			data->prev_pipe = pipefd[0];
		data->i++;
	}
	wait_processes(data);
}


/*
		data->stdin_backup = dup(1);
		printf("befor stdin_backup %i\n", data->stdin_backup);
		data->stdout_backup = dup(0);
		printf("befor stdin_backup %i\n", data->stdout_backup);



//		if (STDIN_FILENO != data->stdin_backup)
		printf("after STDIN_FILENO %i\n", STDIN_FILENO);
		printf("after STDOUT_FILENO %i\n", STDOUT_FILENO);
		printf("------\nstdin_backup %i\n", data->stdin_backup);
		printf("stdin_backup %i\n", data->stdout_backup);
 		dup2(data->stdin_backup, STDIN_FILENO);
		printf("after dup2 STDIN_FILENO %i\n", STDIN_FILENO);
//		if (STDOUT_FILENO != data->stdout_backup)
 	    dup2(data->stdout_backup, STDOUT_FILENO);
		printf("after dup2 STDOUT_FILENO %i\n", STDOUT_FILENO);
 		close(data->stdin_backup);
 		close(data->stdout_backup);
		*/