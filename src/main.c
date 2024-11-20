/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artemii <artemii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 16:16:35 by azakharo          #+#    #+#             */
/*   Updated: 2024/11/19 01:42:13 by artemii          ###   ########.fr       */
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

char	**copy_envp(char **envp)
{
	int		i;
	int		count;
	char	**new_envp;

	count = 0;
	while (envp[count] != NULL)
		count++;
	new_envp = malloc(sizeof(char *) * (count + 1));
	if (!new_envp)
		return (NULL);
	i = 0;
	while (i < count)
	{
		new_envp[i] = ft_strdup(envp[i]); // Дублирую каждую строку
		if (!new_envp[i])
		{
			while (--i >= 0)
				free(new_envp[i]);
			free(new_envp);
			return (NULL);
		}
		i++;
	}
	new_envp[count] = NULL;
	return (new_envp);
}

void	free_data_cmd(t_data *data)
{
	int	i;
	int	j;

	// Освобождаем каждую команду в data->cmd
	i = 0;
	if (data->cmd)
	{
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
			if (data->cmd[i]->here_doc_pfd != 0)
				//Закрываем канал чтения из here doc
			{
				close(data->cmd[i]->here_doc_pfd);
				data->cmd[i]->here_doc_pfd = 0;
			}
			free(data->cmd[i]);
			i++;
		}
		free(data->cmd);
		data->cmd = NULL;
	}
}

void	free_envp(t_data *data)
{
	int	i;

	i = 0;
	while (data->envp[i] != NULL)
	{
		free(data->envp[i]);
		i++;
	}
	free(data->envp);
	data->envp = NULL;
}

void	free_all_data(t_data *data)
{
	if (data)
	{
		if (data->cmd != NULL)
			free_data_cmd(data); // Освобождаем команды и связанные строки
		if (data->envp != NULL)
			free_envp(data); // Освобождаем переменные окружения
		if (data->user_input != NULL)
			free(data->user_input);
		free(data); // Освобождаем структуру data
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_data	*data;
	int		exit_status;

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
	data = malloc(sizeof(t_data));
	if (!data)
	{
		perror("malloc failed");
		return (1);
	}
	ft_memset(data, 0, sizeof(t_data));
	data->envp = copy_envp(envp); //Считываем окружение , нужно для execve
	while (1)
	{
		data->user_input = readline("minishell$ ");
		if (!data->user_input)
		{
			ft_printf("exit\n");
			break ;
		}
		if (ft_strlen(data->user_input) > 0)
			add_history(data->user_input);
		data->back_in_main = 0;
		parse_pipeline(data, data->user_input);
		//Перед запуском новой команды подгружаем статус старой команды
		if (data->back_in_main == 1)
		{
			exit_status = data->exit_status;
			free_data_cmd(data);
			free(data->user_input);
			//printf("status after return (in main with fault %i\n", data->exit_status);
			continue ; // Пропускаем выполнение команды
		}
		data->exit_status = exit_status;
		print_commands(data);    // Вывод команд для дебага
		printf("\n---------\n"); //Отделяем вывод команды от дебага
		choice_execution(data);
		// printf("status %i\n", data->exit_status);
		exit_status = data->exit_status;	//Сохраняем статус завершения команды перед освобождением
		free_data_cmd(data);
		free(data->user_input);
	}
	free_all_data(data);
	rl_clear_history();
	return (0);
}
