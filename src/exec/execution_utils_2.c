/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmychaly <mmychaly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 04:19:01 by mmychaly          #+#    #+#             */
/*   Updated: 2024/11/18 04:08:02 by mmychaly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void handle_sigint(int sig) //Обработчик сигнала SIGINT == ctrl c
{
	(void) sig;
	if (g_pid == -1 || g_pid == -50) //Если мы в родительском процессе, просто выводим новую строку minishell$ и пермещаемся на нее
	{
		write(1, "\n", 2);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
		g_pid = -50;
	}
	else if (g_pid == -5) //Если мы в родительском процессе но here doc . Останавливаем here doc
	{
		write(1, "\n", 1);
		close(0);//Закрытие стандартного ввода сразу прекращает работу функции gnl и выкидывает из цикла 
		g_pid = -10; //Показываем функции here doc что она закончила цикл из за SIGINT
	}
	else if (g_pid > 0)//Если в момент получения SIGINT есть дочерний процесс мы его закроем, при этом родительский процесс на сигнал не реагирует, только получает статус дочернего процесса закрытого по сигналу
		kill(g_pid, SIGINT); //Функция для закрытия дочерних процессов
}

void	wait_processes(t_data *data)
{
	int	pid;
	int	status;
	int signal;
	pid = waitpid(-1, &status, 0);
	while (pid > 0)
	{
		if (pid == data->prev_pipe) //Здесь я неуверен
		{
			if (WIFEXITED(status))
				data->exit_status = (WEXITSTATUS(status));
			else if (WIFSIGNALED(status)) 
			{
				signal = WTERMSIG(status);//Обрабатывает закрытие процесса через сигналы 
				data->exit_status = 128 + signal;
				if (data->exit_status == 131) //Статус закрытия процесса через sigquit
					write(STDOUT_FILENO, "Quit (core dumped)\n", 19);
				else if	(data->exit_status == 130) //Статус закрытия процесса через sigint
					write(STDOUT_FILENO, "\n", 1);
			}
			else
				data->exit_status = 1;
		}
		pid = waitpid(-1, &status, 0);
	}
	g_pid = -1;//После того как точно закрыли все дочерний процессы и находимся в родительском 
	//требуется вернуть глобальную переменную к -1 и можно возвращаться в основной цикл на новый круг.
}
