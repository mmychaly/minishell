/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit_utils_3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmychaly <mmychaly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 16:55:56 by mmychaly          #+#    #+#             */
/*   Updated: 2024/11/25 01:04:39 by mmychaly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	exit_cmds_builtin(t_data *data, char *error, int status, char *most_by_free)
{
	if (error != NULL)
		write(2, error, ft_strlen(error));
	if (most_by_free != NULL)
		free(most_by_free);
	if (data->nb_pipe == 0 && data->builtin_cmd == 1)
	{
		data->back_in_main = 1;
		data->exit_status = status;
		return (data->back_in_main);
	}
	else
	{
		free_all_data(data);
		rl_clear_history();
		exit (status);
	}
	return (data->back_in_main);
}

void	close_here_doc_pfd(int fd)
{
	free_pipe(fd);
	close(fd);
	fd = 0;
}

void	exit_eof(char *lim)
{
	ft_printf("\nwarning: here-document delimited");
	ft_printf(" by end-of-file (wanted '%s')\n", lim);
}

void	exit_only_child(t_data *data, int status)
{
	free_all_data(data);
	rl_clear_history();
	exit(status);
}

int	exit_open(t_data *data, int fd_out)
{
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
	return (0);
}
