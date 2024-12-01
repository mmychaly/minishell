/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_shlvl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artemii <artemii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 02:17:52 by artemii           #+#    #+#             */
/*   Updated: 2024/11/25 02:17:52 by artemii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

/* Функция для проверки наличия SHELL_FLAG в envp*/
static int	check_shell_flag(t_data *data)
{
	int	i;

	i = 0;
	while (data->envp[i] != NULL)
	{
		if (ft_strncmp(data->envp[i], "SHELL_FLAG=", 11) == 0)
			return (1);
		i++;
	}
	return (0);
}

static char	*create_shlvl_str(int shlvl)
{
	char	*shlvl_str;
	char	*new_shlvl;

	shlvl_str = ft_itoa(shlvl);
	if (!shlvl_str)
	{
		perror("ft_itoa failed");
		return (NULL);
	}
	new_shlvl = malloc(7 + ft_strlen(shlvl_str) + 1);
	if (!new_shlvl)
	{
		perror("malloc failed");
		free(shlvl_str);
		return (NULL);
	}
	ft_strlcpy(new_shlvl, "SHLVL=", 7);
	ft_strlcpy(new_shlvl + 6, shlvl_str, ft_strlen(shlvl_str) + 1);
	free(shlvl_str);
	return (new_shlvl);
}

/*Функция для обновления SHLVL*/
void	add_shell_flag(t_data *data, char **new_shlvl, int *shlvl)
{
	char	*new_flag;

	new_flag = ft_strdup("SHELL_FLAG=1");
	if (!new_flag)
	{
		perror("ft_strdup failed");
		return ;
	}
	if (update_or_add_var(data, new_flag, "SHELL_FLAG") == -1)
	{
		free(new_flag);
		return ;
	}
	*new_shlvl = create_shlvl_str(*shlvl);
}

void	update_shlvl(t_data *data)
{
	char	*new_shlvl;
	char	*shlvl_value;
	int		i;
	int		shlvl;

	new_shlvl = NULL;
	shlvl = 1;
	i = 0;
	if (!check_shell_flag(data))
		add_shell_flag(data, &new_shlvl, &shlvl);
	else
	{
		while (data->envp[i++] != NULL)
		{
			if (ft_strncmp(data->envp[i], "SHLVL=", 6) == 0)
			{
				shlvl_value = data->envp[i] + 6;
				shlvl = ft_atoi(shlvl_value) + 1;
				break ;
			}
		}
		new_shlvl = create_shlvl_str(shlvl);
	}
	if (new_shlvl && update_or_add_var(data, new_shlvl, "SHLVL") == -1)
		return (free(new_shlvl));
}
