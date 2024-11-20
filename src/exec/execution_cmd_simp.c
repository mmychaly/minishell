/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_cmd_simp.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmychaly <mmychaly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 00:53:45 by mmychaly          #+#    #+#             */
/*   Updated: 2024/11/18 03:36:39 by mmychaly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	read_line_here_doc(t_cmd *cmd, int pipefd)
{
	char	*line;
	char	*lim;

	lim = cmd->here_doc_file;
	write(1, "> ", 2);
	line = get_next_line(0);
	while (line != NULL)
	{
		if (ft_strncmp(line, lim, ft_strlen(lim)) == 0 && line[ft_strlen(lim)] == '\n' && line[0] != '\n')
		{
			free(line);
			break ;
		}
		else
		{
			write(pipefd, line, ft_strlen(line));
			free(line);
			write(1, "> ", 2);
			line = get_next_line(0);
		}
	}
	if (line == NULL && g_pid != -10)//Выход по сигналу EOF == CTRL D
		ft_printf("\nwarning: here-document delimited by end-of-file (wanted '%s')\n", lim);
}

void	execution_here_doc(t_cmd *cmd, t_data *data)
{
	int		pipefd[2];
	int		in;

	g_pid = -5;
	if (pipe(pipefd) == -1)
		return ;
	in = dup(0);
	read_line_here_doc(cmd, pipefd[1]);
	if (g_pid == -10)//Выход по сигналу SIGINT == CTRL C
	{
		sigint_heredoc(data, pipefd, in);
        return ; 
    }
	close(pipefd[1]);
	close(in);
	cmd->here_doc_pfd = pipefd[0];
	g_pid = -1;
	if (cmd->cmd == NULL)//Если команды не существует
	{
		free_pipe(cmd->here_doc_pfd);//Освобождаем данные из пайпа
		close(cmd->here_doc_pfd);//Закрываем канал чтения
		cmd->here_doc_pfd = 0;
	}
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
	if (data->cmd[data->i]->cmd == NULL)//Если команды нет то выходим в родительский процесс
	{
		free_all_data(data);//Есть ли каналы которые нужно закрыть? 
		exit(0);
	}
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
		if (data->cmd[data->i]->here_doc_pfd != 0 )//Закрытие канала на чтения текущий команды в родительском процессе
		{
			close(data->cmd[data->i]->here_doc_pfd);
			data->cmd[data->i]->here_doc_pfd = 0;
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


/*void	read_line_here_doc(t_data *data, int pipefd)
{
	char	*line;
	char	*lim;

	lim = data->cmd[data->i]->here_doc_file;
	write(1, "> ", 2);
	line = get_next_line(0);
	while (line != NULL)
	{
		if (ft_strncmp(line, lim, ft_strlen(lim)) == 0 && line[ft_strlen(lim)] == '\n' && line[0] != '\n')
		{
			free(line);
			break ;
		}
		else
		{
			write(pipefd, line, ft_strlen(line));
			free(line);
			write(1, "> ", 2);
			line = get_next_line(0);
		}
	}
	if (line == NULL && g_pid != -10)
		ft_printf("\nwarning: here-document delimited by end-of-file (wanted '%s')\n", lim);
}

void	execution_here_doc(t_data *data)
{
	int		pipefd[2];
	int		in;
	
	g_pid = -5;
	if (pipe(pipefd) == -1)
		return ;
	in = dup(0);
	read_line_here_doc(data, pipefd[1]);
	if (g_pid == -10)
	{
		sigint_heredoc(data, pipefd, in);
        return; 
    }
	close(pipefd[1]);
	close(in);
	data->here_doc_pfd = pipefd[0];
	g_pid = -1;
	if (data->cmd[data->i]->cmd == NULL)//Если команды не существует
	{
		free_pipe(data->here_doc_pfd);//Освобождаем данные из пайпа
		close(data->here_doc_pfd);//Закрываем канал чтения
		data->heredoc_interrupted = 1;//Ставим флаг для возвращения в майн
		data->exit_status = 0;
	}
}


		if (data->cmd[data->i]->here_doc_file != NULL)
		{
			execution_here_doc(data);
			if (data->back_in_main != 0)//Если значение 0 значит работа here doc завершилась не корректно и нам нужно обратно в главный цикл
				return ;
			if (data->here_doc_pfd == -1)
				write(2, "ERROR in here_doc\n", 18);
		}*/

	
