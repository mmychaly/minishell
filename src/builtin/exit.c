/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmychaly <mmychaly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 21:11:52 by mmychaly          #+#    #+#             */
/*   Updated: 2024/11/24 21:03:42 by mmychaly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_atoi_mod(const char *nptr)
{
	int		i;
	int		negativ;
	long	result;

	i = 0;
	negativ = 1;
	result = 0;
	if (nptr[i] == '+' || nptr[i] == '-')
		if (nptr[i++] == '-')
			negativ *= -1;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = (result * 10) + (nptr[i] - '0');
		if (result > INT_MAX)
			break ;
		i++;
	}
	result = result * negativ;
	if (result > INT_MAX)
		return (INT_MAX);
	else if (result < INT_MIN)
		return (INT_MIN);
	return (result);
}

void	check_isdigit(t_data *data)
{
	int	i_2;
	int	flag;

	i_2 = 0;
	flag = 0;
	while (data->cmd[data->i]->cmd_arg[1][i_2] != '\0')
	{
		if (flag == 0 && (data->cmd[data->i]->cmd_arg[1][i_2] == '-'
			|| data->cmd[data->i]->cmd_arg[1][i_2] == '+'))
		{
			flag = 1;
			i_2++;
		}
		if (ft_isdigit(data->cmd[data->i]->cmd_arg[1][i_2]) == 0)
		{
			write(2, "exit: numeric argument required\n", 32);
			free_all_data(data);
			rl_clear_history();
			exit(2);
		}
		i_2++;
	}
}

void	select_exit(t_data *data, int status)
{
	int	last_exit;
	int	flag;

	flag = 0;
	last_exit = data->exit_status;
	if (data->cmd[data->i]->cmd_arg[1] != NULL)
		flag = 1;
	free_all_data(data);
	rl_clear_history();
	if (flag == 1)
		exit(status);
	else
		exit(last_exit);
}

void	exit_total(t_data *data)
{
	int	status;
	int	nbr_args;

	nbr_args = 0;
	status = 0;
	if (data->nb_pipe != 0)
		close_input(data);
	while (data->cmd[data->i]->cmd_arg[nbr_args] != NULL)
		nbr_args++;
	if (data->nb_pipe == 0)
		write(2, "exit\n", 5);
	if (data->cmd[data->i]->cmd_arg[1] != NULL)
	{
		check_isdigit(data);
		if (nbr_args > 2)
			if (exit_cmds_builtin(data, "exit: too many arguments\n", 1, NULL)
				== 1)
				return ;
		status = ft_atoi(data->cmd[data->i]->cmd_arg[1]);
		if (status < 0 || status > 255)
			status = status % 256;
	}
	select_exit(data, status);
}
