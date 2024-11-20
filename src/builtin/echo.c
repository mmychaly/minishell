/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmychaly <mmychaly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 02:23:35 by mmychaly          #+#    #+#             */
/*   Updated: 2024/11/13 22:14:17 by mmychaly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	close_input(t_data *data)
{
	if (data->cmd[data->i]->input_file)//Если был пайп закрываем редирекцию из него 
		close(0);
	if (data->flag_pipe == 1)//Если был пайп или here doc то освобождаем пайп + закрываем редирекцию
	{
		free_pipe(0);
		close(0);
	}
}

int	check_option_n(char *arg)
{
	int i;

	i = 0;
	if (arg[i] == '-')//Попускаем -
		i++;
	else 
		return (0);
	while (arg[i] != '\0' && arg[i] == 'n')//Пропускаем все n
		i++;
	if (arg[i] == '\0')//Если мы дошли до конца строки то то сдесь были только n значит это опция
		return (1);
	return (0);
}

void	echo(t_data *data)
{
	int i_2;
	int n;

	i_2 = 1;
	n = 0;
	if (data->nb_pipe != 0)//Закрываем в составной команде
		close_input(data);
	if (data->cmd[data->i]->cmd_arg[i_2] == NULL)//Если нет аргумента просто выводим новую строку возврщаясь в Main
	{
		write(1, "\n", 1);
		if (data->nb_pipe != 0)//Если в составной команде , выходим из дочернего процесса
		{
			close(1);
			free_all_data(data);
			exit (EXIT_SUCCESS);
		}
		else//Если в одиночной команде то просто возвращаемся в main
		{
			data->back_in_main = 1;
			data->exit_status = 0;
			return ;
		}
	}
	while (data->cmd[data->i]->cmd_arg[i_2] != NULL && check_option_n(data->cmd[data->i]->cmd_arg[i_2]) == 1)
	{
		n = 1; //Этот цикл проверяет весь аргументы и ищет первый аргумент который не является опцией, причем одна и таже опция может быть в нескольких аргуменатах echo -nnnn -nnn salut . Выводимый аргумент  salut 
		i_2++;
	}
	if (n == 1 && data->cmd[data->i]->cmd_arg[i_2] == NULL) //Если есть опция но нет выводимого аргумента просто выходим из функции 
	{
		if (data->nb_pipe != 0)
		{
			close(1);
			free_all_data(data);
			exit (EXIT_SUCCESS);
		}
		else
		{
			data->back_in_main = 1;
			data->exit_status = 0;
			return ;
		}
	}
	while (data->cmd[data->i]->cmd_arg[i_2] != NULL)//Выводим все аргументы которые не являються опцией
	{
		ft_putstr_fd(data->cmd[data->i]->cmd_arg[i_2], 1);//Выводим аргумент 
		if (data->cmd[data->i]->cmd_arg[i_2 + 1] != NULL) //Если после текущего аргумента есть еще 1 то ставим пробел
			write(1, " ", 1);
		else if ( n == 0)//Если нет следующего аргумента а так же не было опции то ставим знак новой строки 
			write(1, "\n", 1);
		i_2++;
	}
	if (data->nb_pipe != 0)//Выходим
	{
		close(1);
		free_all_data(data);
		exit (EXIT_SUCCESS);
	}
	else
	{
		data->back_in_main = 1;
		data->exit_status = 0;
		return ;
	}
}


