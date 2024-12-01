/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmychaly <mmychaly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 02:23:35 by mmychaly          #+#    #+#             */
/*   Updated: 2024/11/22 20:48:48 by mmychaly         ###   ########.fr       */
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
	int	i;

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

void	display_str(t_data *data, int i_2, int n)
{
	while (data->cmd[data->i]->cmd_arg[i_2] != NULL)
	{
		ft_putstr_fd(data->cmd[data->i]->cmd_arg[i_2], 1);
		if (data->cmd[data->i]->cmd_arg[i_2 + 1] != NULL)
			write(1, " ", 1);
		else if (n == 0)
			write(1, "\n", 1);
		i_2++;
	}
}

void	echo(t_data *data)
{
	int	i_2;
	int	n;

	i_2 = 1;
	n = 0;
	if (data->nb_pipe != 0)
		close_input(data);
	if (data->cmd[data->i]->cmd_arg[i_2] == NULL)
	{
		write(1, "\n", 1);
		if (exit_cmds_builtin(data, NULL, 0, NULL) == 1)
			return ;
	}
	while (data->cmd[data->i]->cmd_arg[i_2] != NULL
		&& check_option_n(data->cmd[data->i]->cmd_arg[i_2]) == 1)
	{
		n = 1;
		i_2++;
	}
	if (n == 1 && data->cmd[data->i]->cmd_arg[i_2] == NULL)
		if (exit_cmds_builtin(data, NULL, 0, NULL) == 1)
			return ;
	display_str(data, i_2, n);
	if (exit_cmds_builtin(data, NULL, 0, NULL) == 1)
		return ;
}
