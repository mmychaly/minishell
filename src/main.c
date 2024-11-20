/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmychaly <mmychaly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 16:16:35 by azakharo          #+#    #+#             */
/*   Updated: 2024/11/05 22:59:12 by mmychaly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int g_pid;

void	print_commands(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->cmd[i] != NULL)
	{
		ft_printf("Command[%d]:\n", i);
		if (data->cmd[i]->cmd)
			ft_printf("  cmd: %s\n",
				data->cmd[i]->cmd ? data->cmd[i]->cmd : "(null)");
		if (data->cmd[i]->cmd_arg)
		{
			j = 0;
			while (data->cmd[i]->cmd_arg[j] != NULL)
			{
				ft_printf("  cmd_arg[%d]: %s\n", j, data->cmd[i]->cmd_arg[j]);
				j++;
			}
		}
		else
			ft_printf("  cmd_arg: (null)\n");
		if (data->cmd[i]->input_file)
			ft_printf("  input_file: %s (pos_input: %d)\n",
				data->cmd[i]->input_file, data->cmd[i]->pos_input);
		else
			ft_printf("  input_file: (null)\n");
		if (data->cmd[i]->here_doc_file)
			ft_printf("  here_doc_file: %s (pos_here_doc: %d)\n",
				data->cmd[i]->here_doc_file, data->cmd[i]->pos_here_doc);
		else
			ft_printf("  here_doc_file: (null)\n");
		if (data->cmd[i]->output_file)
			ft_printf("  output_file: %s (pos_output: %d)\n",
				data->cmd[i]->output_file, data->cmd[i]->pos_output);
		else
			ft_printf("  output_file: (null)\n");
		if (data->cmd[i]->append_file)
			ft_printf("  append_file: %s (pos_append: %d)\n",
				data->cmd[i]->append_file, data->cmd[i]->pos_append);
		else
			ft_printf("  append_file: (null)\n");
		i++;
	}
}

void	free_data(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->cmd[i] != NULL)
	{
		if (data->cmd[i]->cmd_arg)
		{
			j = 0;
			while (data->cmd[i]->cmd_arg[j])
			{
				free(data->cmd[i]->cmd_arg[j]);
				j++;
			}
			free(data->cmd[i]->cmd_arg);
		}
		if (data->cmd[i]->cmd)
			free(data->cmd[i]->cmd);
		if (data->cmd[i]->input_file)
			free(data->cmd[i]->input_file);
		if (data->cmd[i]->here_doc_file)
			free(data->cmd[i]->here_doc_file);
		if (data->cmd[i]->output_file)
			free(data->cmd[i]->output_file);
		if (data->cmd[i]->append_file)
			free(data->cmd[i]->append_file);
		free(data->cmd[i]);
		i++;
	}
	free(data->cmd);
	free(data);
}

int	main(int argc, char **argv, char **envp)
{
	char	*user_input;
	t_data	*data;
	int exit_status;
	

//	(void)argc;
	(void)argv;
	if (argc > 2) //Проверка на количество аргументов
	{
		write(2, "Too many arguments\n", 19);
		return (1);
	}
	exit_status = 0;
	g_pid = -1; //-1 == родительский процесс
	signal(SIGINT, handle_sigint); //Функция которая обрабатывает сигнал ctrl c , во всех процессах
	signal(SIGQUIT, SIG_IGN); //Функция которая обрабатывает сигнал ctrl '\' . В родительском процессе , игнорирует сигнал
	while (1)
	{
		user_input = readline("minishell$ ");
		if (!user_input)
			break ;
		if (ft_strlen(user_input) > 0)
			add_history(user_input);
		data = malloc(sizeof(t_data));
		if (!data)
		{
			perror("malloc failed");
			return (1);
		}
		ft_memset(data, 0, sizeof(t_data));
		data->envp = envp; //Считываем окружение , нужно для execve
		parse_pipeline(data, user_input);
		data->exit_status = exit_status; //Перед запуском новой команды подгружаем статус старой команды
		print_commands(data);    // Вывод команд для дебага
		printf("\n---------\n"); //Отделяем вывод команды от дебага
		choice_execution(data);
		printf("status %i\n", data->exit_status);
		exit_status = data->exit_status; //Сохраняем статус завершения команды перед освобождением
		free_data(data);
		free(user_input);
	}
	rl_clear_history();
	return (0);
}
