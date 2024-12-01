/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmychaly <mmychaly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 00:47:25 by artemii           #+#    #+#             */
/*   Updated: 2024/11/25 01:24:17 by mmychaly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_redirection_in(t_data *data)
{
	int	fd_in;

	manage_fd_redirection_input(data, 1);
	if (check_input_files(data, 0) == 1)
		return ;
	fd_in = open(data->cmd[data->i]->input_file, O_RDONLY, 0644);
	if (fd_in == -1)
	{
		perror("Error opening input file");
		if (data->i != data->nb_pipe)
			close(data->pipefd[1]);
		if (exit_cmds_builtin(data, NULL, 1, NULL) == 1)
			return ;
	}
	if (data->nb_pipe == 0 && data->builtin_cmd == 1)
		close(fd_in);
	else
	{
		redirection_input_stdin(data, fd_in);
		close(fd_in);
		data->flag_pipe = 0;
	}
}

void	ft_redirection_here_doc(t_data *data)
{
	manage_fd_redirection_input(data, 0);
	if (check_input_files(data, 1) == 1)
		return ;
	if ((data->nb_pipe == 0 && data->builtin_cmd == 1)
		|| data->cmd[data->i]->cmd == NULL)
		close_here_doc_pfd(data->cmd[data->i]->here_doc_pfd);
	else
	{
		redirection_here_doc_stdin(data);
		close(data->cmd[data->i]->here_doc_pfd);
		data->cmd[data->i]->here_doc_pfd = 0;
		data->flag_pipe = 1;
	}
}

void	ft_redirection_pipe(t_data *data)
{
	if (data->i != data->nb_pipe)
		close(data->pipefd[0]);
	if (dup2(data->prev_pipe, STDIN_FILENO) == -1)
	{
		perror("Error: dup2 prev_pipe");
		free_pipe(data->prev_pipe);
		close(data->prev_pipe);
		if (data->i != data->nb_pipe)
			close(data->pipefd[1]);
		free_all_data(data);
		rl_clear_history();
		exit (EXIT_FAILURE);
	}
	close(data->prev_pipe);
	data->flag_pipe = 1;
}

void	ft_redirection_out_cmd(t_data *data)
	{
	int	fd_out;

	manage_fd_redirection_output(data);
	if (data->cmd[data->i]->pos_append > data->cmd[data->i]->pos_output)
	{
		if (check_files(data, 1) == 1)
			return ;
		fd_out = open(data->cmd[data->i]->append_file, O_WRONLY
				| O_CREAT | O_APPEND, 0644);
	}
	else
	{
		if (check_files(data, 0) == 1)
			return ;
		fd_out = open(data->cmd[data->i]->output_file, O_WRONLY
				| O_TRUNC | O_CREAT, 0644);
	}
	if (exit_open(data, fd_out) == 1)
		return ;
	if (redirection_output(data, fd_out) == 1)
		return ;
}

void	ft_redirection_out_pipe(t_data *data)
{
	if (dup2(data->pipefd[1], STDOUT_FILENO) == -1)
	{
		perror("Error: dup2 pipefd[1]");
		if (data->flag_pipe > 0)
			free_pipe(0);
		close(data->pipefd[1]);
		free_all_data(data);
		rl_clear_history();
		exit (EXIT_FAILURE);
	}
	close(data->pipefd[1]);
}
