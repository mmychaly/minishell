/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artemii <artemii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 16:16:35 by azakharo          #+#    #+#             */
/*   Updated: 2024/12/01 17:47:31 by artemii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int			g_pid;

void		print_commands(t_data *data);

static int	init_data(t_data **data, char **envp)
{
	*data = malloc(sizeof(t_data));
	if (!(*data))
	{
		perror("malloc failed");
		return (1);
	}
	ft_memset(*data, 0, sizeof(t_data));
	(*data)->envp = copy_envp(envp);
	if (!(*data)->envp)
	{
		perror("copy_envp failed");
		free(*data);
		return (1);
	}
	update_shlvl(*data);
	return (0);
}

static void	process_user_input(t_data *data, int *exit_status)
{
	if (!data->user_input)
	{
		ft_printf("exit\n");
		free_all_data(data);
		rl_clear_history();
		exit(*exit_status);
	}
	if (ft_strlen(data->user_input) > 0)
		add_history(data->user_input);
}

static void	execute_pipeline(t_data *data, int *exit_status)
{
	choice_execution(data);
	*exit_status = data->exit_status;
	free_data_cmd(data);
	free(data->user_input);
}

static void	parse_and_execute(t_data *data, int *exit_status)
{
	parse_pipeline(data, data->user_input);
	if (data->back_in_main == 1)
	{
		*exit_status = data->exit_status;
		free_data_cmd(data);
		free(data->user_input);
		return ;
	}
	execute_pipeline(data, exit_status);
}

int	main(int argc, char **argv, char **envp)
{
	t_data	*data;
	int		exit_status;

	(void)argv;
	if (argc > 2)
	{
		write(2, "Too many arguments\n", 19);
		return (1);
	}
	handle_signals();
	if (init_data(&data, envp) != 0)
		return (1);
	exit_status = 0;
	while (1)
	{
		data->user_input = readline("minishell$ ");
		process_user_input(data, &exit_status);
		reset_data_flags(data);
		handle_pid_status(data, &exit_status);
		parse_and_execute(data, &exit_status);
	}
	return (0);
}
/*
void	print_commands(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->cmd[i] != NULL)
	{
		ft_printf("Command[%d]:\n", i);
		if (data->cmd[i]->cmd)
			ft_printf("  cmd: %s\n", data->cmd[i]->cmd);
		else
			ft_printf("  cmd: (null)\n");
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
		// Print positions
		ft_printf("  pos_input: %d\n", data->cmd[i]->pos_input);
		ft_printf("  pos_output: %d\n", data->cmd[i]->pos_output);
		ft_printf("  pos_append: %d\n", data->cmd[i]->pos_append);
		ft_printf("  pos_here_doc: %d\n", data->cmd[i]->pos_here_doc);
		// Final input, output, append, and here_doc files
		if (data->cmd[i]->input_file)
			ft_printf("  final_input: %s\n", data->cmd[i]->input_file);
		else
			ft_printf("  final_input: (null)\n");
		if (data->cmd[i]->output_file)
			ft_printf("  final_output: %s\n", data->cmd[i]->output_file);
		else
			ft_printf("  final_output: (null)\n");
		if (data->cmd[i]->append_file)
			ft_printf("  final_append_file: %s\n", data->cmd[i]->append_file);
		else
			ft_printf("  final_append_file: (null)\n");
		if (data->cmd[i]->here_doc_file)
			ft_printf("  final_here_doc_file: %s\n",
				data->cmd[i]->here_doc_file);
		else
			ft_printf("  final_here_doc_file: (null)\n");
		// Print arrays of files
		if (data->cmd[i]->input_files)
		{
			j = 0;
			while (data->cmd[i]->input_files[j] != NULL)
			{
				ft_printf("  input_files[%d]: %s\n", j,
					data->cmd[i]->input_files[j]);
				j++;
			}
		}
		else
			ft_printf("  input_files: (null)\n");
		if (data->cmd[i]->output_files)
		{
			j = 0;
			while (data->cmd[i]->output_files[j] != NULL)
			{
				ft_printf("  output_files[%d]: %s\n", j,
					data->cmd[i]->output_files[j]);
				j++;
			}
		}
		else
			ft_printf("  output_files: (null)\n");
		if (data->cmd[i]->append_files)
		{
			j = 0;
			while (data->cmd[i]->append_files[j] != NULL)
			{
				ft_printf("  append_files[%d]: %s\n", j,
					data->cmd[i]->append_files[j]);
				j++;
			}
		}
		else
			ft_printf("  append_files: (null)\n");
		if (data->cmd[i]->here_doc_files)
		{
			j = 0;
			while (data->cmd[i]->here_doc_files[j] != NULL)
			{
				ft_printf("  here_doc_files[%d]: %s\n", j,
					data->cmd[i]->here_doc_files[j]);
				j++;
			}
		}
		else
			ft_printf("  here_doc_files: (null)\n");
		i++;
	}
}
*/
