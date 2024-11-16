/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_var.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artemii <artemii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 00:06:56 by artemii           #+#    #+#             */
/*   Updated: 2024/11/15 01:30:28 by artemii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// Удаление переменной из окружения
static void	remove_env_var(t_data *data, int i)
{
	free(data->envp[i]);
	while (data->envp[i])
	{
		data->envp[i] = data->envp[i + 1];
		i++;
	}
	data->envp[i] = NULL;
}

static void	unset_exit(t_data *data, int status)
{
	if (data->nb_pipe == 0)
	{
		data->back_in_main = 1;
		data->exit_status = status;
	}
	else
	{
		close(1);
		free_all_data(data);
		exit(status);
	}
}

void	unset_var(t_data *data, char *key)
{
	int	key_len;
	int	i;

	if (!key || key[0] == '\0')
	{
		unset_exit(data, 0);
		return ;
	}
	key_len = ft_strlen(key);
	if (data->nb_pipe != 0)
		close_input(data);
	i = 0;
	while (data->envp[i])
	{
		if (ft_strncmp(data->envp[i], key, key_len) == 0
			&& data->envp[i][key_len] == '=')
		{
			remove_env_var(data, i);
			unset_exit(data, 0);
			return ;
		}
		i++;
	}
	unset_exit(data, 0);
}
