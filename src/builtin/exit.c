/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:   ) //Для exit
	{ :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmychaly <mmychaly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 17:27:51 by mmychaly          #+#    #+#             */
/*   Updated: 2024/11/11 04:32:33 by mmychaly         ###   ########.fr       */
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
	{
		if (nptr[i] == '-')
			negativ *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = (result * 10) + (nptr[i] - '0');
		if (result > INT_MAX)//Если число выходит за int то выходим из цикла 
			break;
		i++;
	}
	result = result * negativ;
	if (result > INT_MAX)//Больше инт возвращаем максимальное число инт
		return (INT_MAX);
	else if (result < INT_MIN)//меньше инт возвращем минимальное число инт
		return (INT_MIN);
	return (result);
}

void	exit_total(t_data *data)
{
	int	i_2;
	int flag; //Флаг отвечает за коректное учитывание 1 минуса или плюса
	int	status; //Сохраняем статус выхода
	int	nbr_args; //Требуется что бы обратиться к третьему аргументу если он существует 

	i_2 = 0;
	flag = 0;
	nbr_args = 0;
	status = 0;
	if (data->nb_pipe != 0)//Закрываем input для составных команд
	{
		close_input(data);
		close (1);
	}
	while (data->cmd[data->i]->cmd_arg[nbr_args] != NULL)
		nbr_args++;
	if (data->nb_pipe == 0) //Если это одиночная команда то сразу выводим сообщение, для составных выводить не нужно 
		write(2, "exit\n", 5);
	if (data->cmd[data->i]->cmd_arg[1] != NULL)//Если у команды есть хотя бы 1 аргумент то будем обрабатывать аргумент дабы найти правильный статус выхода
	{
		while (data->cmd[data->i]->cmd_arg[1][i_2] != '\0') //Идем  до конца строки если в строке есть что то помимо цифр и одного + или - то выходим с ошибкой 
		{
			if (flag == 0 && (data->cmd[data->i]->cmd_arg[1][i_2] == '-' || data->cmd[data->i]->cmd_arg[1][i_2] == '+'))
			{
				flag = 1; //Требуется что бы один раз пропустит знак + или -
				i_2++;
			}
			if (ft_isdigit(data->cmd[data->i]->cmd_arg[1][i_2]) == 0)//Проверяем цифра или нет 
			{
				write(2, "exit: numeric argument required\n", 32);
				free_all_data(data);
				rl_clear_history();
				exit(2);
			}
			i_2++;
		}
		if (nbr_args > 2)//Если аргументов больше чем 2 то выходим с ошибкой 
		{
			write(2, "exit: too many arguments\n", 25);
			if (data->nb_pipe == 0)//Если команда одиночная то просто выходим обратно в main
			{
				data->back_in_main = 1;
				data->exit_status = 1;
				return ;
			}
			else//Если команда составная то закрывем процесс и возвращаемся в родительский процесс
			{
				free_all_data(data);
				rl_clear_history();
				exit (1) ;
			}		
		}
		status = ft_atoi(data->cmd[data->i]->cmd_arg[1]);//Трансформируем строку в число 
		if (status < 0 || status > 255)//Если статус больше меньше разрешеного диапазона , делаем modulo
			status = status % 256;
	}
//	free(data->user_input); peut etre ca aussi
	free_all_data(data);
	rl_clear_history();
	exit(status);
}


/*
void	check_exit_total(t_data *data)
{
	int nbr_args;
	int	exit_status;


	nbr_args = 0;
	exit_status = data->exit_status;
	if (ft_strcmp(data->cmd[0]->cmd, "exit") == 0 && data->nb_pipe == 0)
	{
		while (data->cmd[0]->cmd_arg[nbr_args] != NULL)
			nbr_args++;
		if (nbr_args > 2 && exit_status == 1)
			nbr_args++;
		else
		{
//			write(2, "exit---------------------------\n", 32);
			free_data(data);
//			free(data->user_input);
			rl_clear_history();
			exit (exit_status);
		}
	}
}
*/