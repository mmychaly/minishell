/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections_utils_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmychaly <mmychaly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 18:27:10 by mmychaly          #+#    #+#             */
/*   Updated: 2024/11/23 20:35:27 by mmychaly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	check_output_files(t_data *data)
{
	int	fd_out;
	int	i;

	i = 0;
	while (data->cmd[data->i]->output_files[i] != NULL)
	{
		fd_out = open(data->cmd[data->i]->output_files[i], O_WRONLY
				| O_TRUNC | O_CREAT, 0644);
		if (fd_out == -1)
		{
			perror("Error opening output file");
			if (data->flag_pipe > 0)
				free_pipe(0);
			if (data->std_out != 0)
				close(data->std_out);
			if (exit_cmds_builtin(data, NULL, 1, NULL) == 1)
				return (1);
		}
		close(fd_out);
		i++;
	}
	return (0);
}

int	check_append_files(t_data *data)
{
	int	fd_out;
	int	i;

	i = 0;
	while (data->cmd[data->i]->append_files[i] != NULL)
	{
		fd_out = open(data->cmd[data->i]->append_files[i], O_WRONLY
				| O_CREAT | O_APPEND, 0644);
		if (fd_out == -1)
		{
			perror("Error opening output file");
			if (data->flag_pipe > 0)
				free_pipe(0);
			if (data->std_out != 0)
				close(data->std_out);
			if (exit_cmds_builtin(data, NULL, 1, NULL) == 1)
				return (1);
		}
		close(fd_out);
		i++;
	}
	return (0);
}

int	redirection_output_stdout(t_data *data, int fd_out)
{
	if (dup2(fd_out, STDOUT_FILENO) == -1)
	{
		perror("dup2 fd_out");
		if (data->flag_pipe > 0)
			free_pipe(0);
		close(fd_out);
		if (data->std_out != 0)
			close(data->std_out);
		if (data->nb_pipe == 0 && data->builtin_cmd
			== 1 && data->display_builtin_cmd == 1)
		{
			data->back_in_main = 1;
			data->exit_status = 1;
			return (1);
		}
		else
		{
			free_all_data(data);
			rl_clear_history();
			exit (EXIT_FAILURE);
		}
	}
	return (0);
}

int	check_files(t_data *data, int flag)
{
	if (flag == 1)
	{
		if (data->cmd[data->i]->output_file != NULL)
		{
			if (check_output_files(data) == 1)
				return (1);
		}
		if (check_append_files(data) == 1)
			return (1);
	}
	else if (flag == 0)
	{
		if (data->cmd[data->i]->append_file != NULL)
		{
			if (check_append_files(data) == 1)
				return (1);
		}
		if (check_output_files(data) == 1)
			return (1);
	}
	return (0);
}

int	redirection_output(t_data *data, int fd_out)
{
	if (data->nb_pipe == 0 && data->builtin_cmd
		== 1 && data->display_builtin_cmd != 1)
		close(fd_out);
	else
	{
		if (redirection_output_stdout(data, fd_out) == 1)
			return (1);
		close(fd_out);
	}
	return (0);
}
