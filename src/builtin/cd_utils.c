/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artemii <artemii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 20:45:17 by artemii           #+#    #+#             */
/*   Updated: 2024/11/25 20:50:14 by artemii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*handle_no_argument(t_data *data, char *old_pwd)
{
	char	*target_dir;

	target_dir = get_env_value("HOME", data);
	if (!target_dir)
		cd_exit(data, 1, "cd: HOME not set\n", old_pwd);
	return (target_dir);
}

char	*handle_dash_argument(t_data *data, char *old_pwd)
{
	char	*target_dir;

	target_dir = get_env_value("OLDPWD", data);
	if (!target_dir)
		cd_exit(data, 1, "cd: OLDPWD not set\n", old_pwd);
	ft_printf("%s\n", target_dir);
	return (target_dir);
}

char	*handle_tilde_argument(t_data *data, char *arg, char *old_pwd,
		int *free_target_dir)
{
	char	*home;
	char	*target_dir;

	home = get_env_value("HOME", data);
	if (!home)
		cd_exit(data, 1, "cd: HOME not set\n", old_pwd);
	target_dir = ft_strjoin(home, arg + 1);
	if (!target_dir)
		cd_exit(data, 1, "cd: memory allocation failed\n", old_pwd);
	*free_target_dir = 1;
	return (target_dir);
}

int	change_and_update_env(t_data *data, char *target_dir, char *old_pwd)
{
	if (change_directory(data, target_dir) == 0)
	{
		if (update_environment(data, old_pwd) == -1)
		{
			cd_exit(data, 1, NULL, old_pwd);
			return (-1);
		}
	}
	else
	{
		cd_exit(data, 1, NULL, old_pwd);
		return (-1);
	}
	return (0);
}
