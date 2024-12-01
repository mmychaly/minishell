/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_envp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmychaly <mmychaly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 00:12:33 by artemii           #+#    #+#             */
/*   Updated: 2024/11/25 01:50:20 by mmychaly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	print_env(t_data *data)
{
	int	i;

	i = 0;
	if (data->nb_pipe != 0)
		close_input(data);
	while (data->envp[i] != NULL)
	{
		ft_putstr_fd(data->envp[i], STDOUT_FILENO);
		ft_putchar_fd('\n', STDOUT_FILENO);
		i++;
	}
	if (data->nb_pipe == 0)
	{
		data->back_in_main = 1;
		data->exit_status = 0;
		return ;
	}
	else
	{
		free_all_data(data);
		rl_clear_history();
		exit (0);
	}
}
