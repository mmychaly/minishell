/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_cmd_simp.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmychaly <mmychaly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 00:53:45 by mmychaly          #+#    #+#             */
/*   Updated: 2024/11/23 06:02:00 by mmychaly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	read_line_here_doc(char *here_doc_file, int pipefd)
{
	char	*line;
	char	*lim;

	lim = here_doc_file;
	write(1, "> ", 2);
	line = get_next_line(0);
	while (line != NULL)
	{
		if (ft_strncmp(line, lim, ft_strlen(lim)) == 0
			&& line[ft_strlen(lim)] == '\n' && line[0] != '\n')
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
		exit_eof(lim);
}

void	execution_here_doc(t_cmd *cmd, char *here_doc_file, t_data *data)
{
	int		pipefd[2];
	int		in;

	g_pid = -5;
	if (cmd->here_doc_pfd > 0)
		close_here_doc_pfd(cmd->here_doc_pfd);
	if (pipe(pipefd) == -1)
		return ;
	in = dup(0);
	read_line_here_doc(here_doc_file, pipefd[1]);
	if (g_pid == -10)
	{
		sigint_heredoc(data, pipefd, in);
		return ;
	}
	close(pipefd[1]);
	close(in);
	cmd->here_doc_pfd = pipefd[0];
	g_pid = -1;
}

void	redirection(t_data *data)
{
	if (data->cmd[data->i]->pos_here_doc > data->cmd[data->i]->pos_input)
		ft_redirection_here_doc(data);
	else if (data->cmd[data->i]->pos_here_doc < data->cmd[data->i]->pos_input)
		ft_redirection_in(data);
	else if (data->cmd[data->i]->here_doc_file == NULL
		&& data->cmd[data->i]->input_file == NULL && data->prev_pipe != -1)
		ft_redirection_pipe(data);
	else
	{
		if (data->i != data->nb_pipe)
			close(data->pipefd[0]);
	}
	if (data->cmd[data->i]->output_file != NULL
		|| data->cmd[data->i]->append_file != NULL)
		ft_redirection_out_cmd(data);
	else if (data->cmd[data->i]->output_file == NULL
		&& data->cmd[data->i]->append_file == NULL && data->i != data->nb_pipe)
		ft_redirection_out_pipe(data);
	else
	{
		if (data->i != data->nb_pipe)
			close(data->pipefd[1]);
	}
}

void	check_file_args(t_data *data)
{
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
}
