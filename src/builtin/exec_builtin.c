/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmychaly <mmychaly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 04:50:13 by mmychaly          #+#    #+#             */
/*   Updated: 2024/11/25 01:48:08 by mmychaly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	check_builtin_command(t_data *data)
{
	if (ft_strcmp(data->cmd[data->i]->cmd, "exit") == 0
		|| ft_strcmp(data->cmd[data->i]->cmd, "export") == 0
		|| ft_strcmp(data->cmd[data->i]->cmd, "unset") == 0)
		data->builtin_cmd = 1;
	else if (ft_strcmp(data->cmd[data->i]->cmd, "cd") == 0)
	{
		data->builtin_cmd = 1;
		data->display_builtin_cmd = 1;
	}
	else if (ft_strcmp(data->cmd[data->i]->cmd, "env") == 0)
	{
		data->builtin_cmd = 1;
		data->display_builtin_cmd = 1;
	}
	else if (ft_strcmp(data->cmd[data->i]->cmd, "pwd") == 0)
	{
		data->builtin_cmd = 1;
		data->display_builtin_cmd = 1;
	}
	else if (ft_strcmp(data->cmd[data->i]->cmd, "echo") == 0)
	{
		data->builtin_cmd = 1;
		data->display_builtin_cmd = 1;
	}
}

void	redirection_builtin_command(t_data *data)
{
	if (data->cmd[data->i]->pos_here_doc > data->cmd[data->i]->pos_input)
	{
		ft_redirection_here_doc(data);
		if (data->back_in_main == 1)
			return ;
	}
	else if (data->cmd[data->i]->pos_here_doc < data->cmd[data->i]->pos_input)
	{
		ft_redirection_in(data);
		if (data->back_in_main == 1)
			return ;
	}
	if (data->cmd[data->i]->output_file != NULL
		|| data->cmd[data->i]->append_file != NULL)
	{
		ft_redirection_out_cmd(data);
		if (data->back_in_main == 1)
			return ;
	}
}

void	remove_stdout(t_data *data)
{
	if (data->nb_pipe == 0 && data->builtin_cmd == 1
		&& data->display_builtin_cmd == 1
		&& (data->cmd[data->i]->output_file != NULL
			|| data->cmd[data->i]->append_file != NULL))
	{
		if (dup2(data->std_out, 1) == -1)
		{
			perror("Error: dup2 in execute_builtin_command");
			close(data->std_out);
			free_all_data(data);
			rl_clear_history();
			exit(1);
		}
		close(data->std_out);
	}
}

void	launch_func_builtin(t_data *data)
{
	if (ft_strcmp(data->cmd[data->i]->cmd_arg[0], "echo") == 0)
		echo(data);
	else if (ft_strcmp(data->cmd[data->i]->cmd_arg[0], "exit") == 0)
		exit_total(data);
	else if (ft_strcmp(data->cmd[data->i]->cmd_arg[0], "export") == 0)
		export_var(data, data->cmd[data->i]->cmd_arg[1]);
	else if (ft_strcmp(data->cmd[data->i]->cmd_arg[0], "unset") == 0)
		unset_var(data, data->cmd[data->i]->cmd_arg[1]);
	else if (ft_strcmp(data->cmd[data->i]->cmd_arg[0], "env") == 0)
		print_env(data);
	else if (ft_strcmp(data->cmd[data->i]->cmd_arg[0], "pwd") == 0)
		pwd(data);
	else if (ft_strcmp(data->cmd[data->i]->cmd_arg[0], "cd") == 0)
	{
		if (data->cmd[data->i]->cmd_arg[2] != NULL)
			exit_cmds_builtin(data, "cd: too many arguments\n", 1, NULL);
		else
		{
			if (data->cmd[data->i]->cmd_arg[1] == NULL)
				cd(data, NULL);
			else
				cd(data, data->cmd[data->i]->cmd_arg[1]);
		}
	}
}

void	execute_builtin_command(t_data *data)
{
	if (data->cmd[data->i] && data->cmd[data->i]->cmd)
	{
		if (data->cmd[data->i]->cmd == NULL)
		{
			data->back_in_main = 1;
			data->exit_status = 0;
			return ;
		}
		check_builtin_command(data);
		if (data->nb_pipe == 0 && data->builtin_cmd == 1)
			redirection_builtin_command(data);
		if (data->back_in_main == 1)
			return ;
		launch_func_builtin(data);
	}
	remove_stdout(data);
}
