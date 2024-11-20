/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmychaly <mmychaly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 02:23:35 by mmychaly          #+#    #+#             */
/*   Updated: 2024/11/06 05:07:11 by mmychaly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	close_input(t_data *data)
{
	if (data->cmd[data->i]->input_file)
		close(0);
	if (data->flag_pipe == 1)
	{
		free_pipe(0);
		close(0);
	}
}

int	check_option_n(char *arg)
{
	int i;

	i = 0;
	if (arg[i] == '-')
		i++;
	else 
		return (0);
	while (arg[i] != '\0' && arg[i] == 'n')
		i++;
	if (arg[i] == '\0')
		return (1);
	return (0);
}

void	echo(t_data *data)
{
	int i_2;
	int n;

	i_2 = 1;
	n = 0;
	close_input(data);
	if (data->cmd[data->i]->cmd_arg[i_2] == NULL)
	{
		write(1, "\n", 1);
		close(1);
		free_data(data);
		exit (EXIT_SUCCESS);
	}
	while (data->cmd[data->i]->cmd_arg[i_2] != NULL && check_option_n(data->cmd[data->i]->cmd_arg[i_2]) == 1)
	{
		n = 1;
		i_2++;
	}
	if (n == 1 && data->cmd[data->i]->cmd_arg[i_2] == NULL)
	{
		close(1);
		free_data(data);
		exit (EXIT_SUCCESS);
	}
	while (data->cmd[data->i]->cmd_arg[i_2] != NULL)
	{
		ft_putstr_fd(data->cmd[data->i]->cmd_arg[i_2], 1);
		if (data->cmd[data->i]->cmd_arg[i_2 + 1] != NULL)
			write(1, " ", 1);
		else if (n == 0)
			write(1, "\n", 1);
		i_2++;
	}
	close(1);
	free_data(data);
	exit(EXIT_SUCCESS);
}


