/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmychaly <mmychaly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 04:08:02 by mmychaly          #+#    #+#             */
/*   Updated: 2024/11/18 03:35:27 by mmychaly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	free_fault_execve(char *cmd, t_data *data)
{
	free(cmd);
	cmd = NULL;
	if (data->flag_pipe > 0)
		free_pipe(0);
	free_all_data(data);
	perror("ERROR execve");
	exit(126);
}

void	ft_free_strs(char **strs)
{
	int	i;

	i = 0;
	while (strs[i] != NULL)
	{
		free(strs[i]);
		i++;
	}
	free(strs);
	strs = NULL;
}

void	ft_error_exit(int nb)
{
	perror("ERROR");
	if (nb == 0)
		exit(0);
	else
		exit(EXIT_FAILURE);
}

void	free_pipe(int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
	}
}

void	error_join_arg(t_data *data)
{
	write(2, "ERROR join_arg\n", 15);
	if (data->flag_pipe > 0)
		free_pipe(0);
	free_data_cmd(data);
	exit(EXIT_FAILURE);
}