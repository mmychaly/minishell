/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artemii <artemii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 04:50:13 by mmychaly          #+#    #+#             */
/*   Updated: 2024/11/16 19:23:11 by artemii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	execute_builtin_command(t_data *data)
{
	char	**args;

	if (data->cmd[data->i] && data->cmd[data->i]->cmd)
	{
		args = data->cmd[data->i]->cmd_arg;
		if (ft_strcmp(data->cmd[data->i]->cmd, "echo") == 0)
			echo(data);
		else if (ft_strcmp(data->cmd[data->i]->cmd, "exit") == 0)
			exit_total(data);
		else if (ft_strcmp(args[0], "export") == 0)
			export_var(data, args[1]);
		else if (ft_strcmp(args[0], "unset") == 0)
			unset_var(data, args[1]); // Удаляем переменную
		else if (ft_strcmp(args[0], "env") == 0)
			print_env(data);
		else if (ft_strcmp(args[0], "pwd") == 0)
			pwd(data);
	}
}
