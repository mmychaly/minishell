/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_envp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmychaly <mmychaly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 00:12:33 by artemii           #+#    #+#             */
/*   Updated: 2024/11/14 21:12:18 by mmychaly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

//Тупо функция envp :)

void	print_env(t_data *data)
{
	int	i;

	i = 0;
	if (data->nb_pipe != 0)//Закрываем input для составных команд
		close_input(data);
	while (data->envp[i] != NULL)
	{
		ft_putstr_fd(data->envp[i], STDOUT_FILENO);
		ft_putchar_fd('\n', STDOUT_FILENO);
		i++;
	}
	if (data->nb_pipe == 0)//Если команда одиночная то просто выходим обратно в main
	{
		data->back_in_main = 1;
		data->exit_status = 0;
		return ;
	}
	else//Если команда составная то закрывем процесс и возвращаемся в родительский процесс
	{
		close (1);
		free_all_data(data);
	//	rl_clear_history();
		exit (0) ;
	}	
}
