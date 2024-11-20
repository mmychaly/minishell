/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit_utils_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmychaly <mmychaly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 04:07:52 by mmychaly          #+#    #+#             */
/*   Updated: 2024/10/27 22:18:14 by mmychaly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	error_empty_cmd(t_data *data)
{
	write(2, "Error: Empty command\n", 21);
	if (data->flag_pipe > 0)
		free_pipe(0);
	free_data(data);
	exit(127);
}

void	error_cmd(int flag) //Больше нет функции
{
	write(2, "Error: option\n", 14);
	if (flag == 1)
		free_pipe(0);
	exit(127);
}

void	free_error_cmd(t_data *data)
{
	if (data->flag_pipe > 0) // -v
		free_pipe(0);
	free_data(data);
	exit(127);
}

void	error_open_outfile(int flag , t_data *data)
{
	perror("open outfile");
	if (flag == 1)
		free_pipe(0);
	free_data(data);
	exit (1);
}

