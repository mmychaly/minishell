/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artemii <artemii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 01:51:56 by mmychaly          #+#    #+#             */
/*   Updated: 2024/11/25 20:49:44 by artemii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	cd_exit(t_data *data, int status, char *message, char *to_free)
{
	if (message)
		write(2, message, ft_strlen(message));
	if (to_free)
		free(to_free);
	if (data->nb_pipe == 0)
	{
		data->back_in_main = 1;
		data->exit_status = status;
	}
	else
	{
		free_all_data(data);
		rl_clear_history();
		exit(status);
	}
}

/* Получает текущую директорию*/
static char	*get_current_directory(t_data *data)
{
	char	*dir;

	dir = getcwd(NULL, 0);
	if (!dir)
		cd_exit(data, 1, "cd: error retrieving current directory\n", NULL);
	return (dir);
}

/* Смена директории*/
int	change_directory(t_data *data, char *target_dir)
{
	if (chdir(target_dir) == -1)
	{
		perror("cd");
		cd_exit(data, 1, NULL, NULL);
		return (-1);
	}
	return (0);
}

/* Обновляет переменные окружения OLDPWD и PWD*/
int	update_environment(t_data *data, char *old_pwd)
{
	char	*new_pwd;
	char	*export_oldpwd;
	char	*export_newpwd;

	export_oldpwd = NULL;
	export_newpwd = NULL;
	new_pwd = get_current_directory(data);
	if (!new_pwd)
		return (-1);
	export_oldpwd = ft_strjoin("OLDPWD=", old_pwd);
	if (export_oldpwd)
	{
		export_var(data, export_oldpwd);
		free(export_oldpwd);
	}
	export_newpwd = ft_strjoin("PWD=", new_pwd);
	if (export_newpwd)
	{
		export_var(data, export_newpwd);
		free(export_newpwd);
	}
	free(new_pwd);
	return (0);
}

void	cd(t_data *data, char *arg)
{
	char	*old_pwd;
	char	*target_dir;
	int		free_target_dir;

	target_dir = NULL;
	free_target_dir = 0;
	if (data->nb_pipe != 0)
		close_input(data);
	old_pwd = get_current_directory(data);
	if (!old_pwd)
		return ;
	if (!arg)
		target_dir = handle_no_argument(data, old_pwd);
	else if (ft_strcmp(arg, "-") == 0)
		target_dir = handle_dash_argument(data, old_pwd);
	else if (arg[0] == '~')
		target_dir = handle_tilde_argument(data, arg, old_pwd,
				&free_target_dir);
	else
		target_dir = arg;
	if (change_and_update_env(data, target_dir, old_pwd) == -1)
		return ;
	if (free_target_dir)
		free(target_dir);
	cd_exit(data, 0, NULL, old_pwd);
}

/*
static void	cd_exit(t_data *data, int status, char *message, char *to_free)
{
	if (message)
		write(2, message, ft_strlen(message));
	if (to_free)
		free(to_free);
	if (data->nb_pipe == 0)
	{
		data->back_in_main = 1;
		data->exit_status = status;
	}
	else
	{
		free_all_data(data);
		rl_clear_history();
		exit(status);
	}
}

static char	*get_current_directory(t_data *data)
{
	char	*dir;

	dir = getcwd(NULL, 0);
	if (!dir)
		cd_exit(data, 1, "cd: error retrieving current directory\n", NULL);
	return (dir);
}

static int	change_directory(t_data *data, char *target_dir)
{
	if (chdir(target_dir) == -1)
	{
		perror("cd");
		cd_exit(data, 1, NULL, NULL);
		return (-1);
	}
	return (0);
}

static int	update_environment(t_data *data, char *old_pwd)
{
	char	*new_pwd;
	char	*export_oldpwd;
	char	*export_newpwd;

	export_oldpwd = NULL;
	export_newpwd = NULL;
	new_pwd = get_current_directory(data);
	if (!new_pwd)
		return (-1);
	export_oldpwd = ft_strjoin("OLDPWD=", old_pwd);
	if (export_oldpwd)
	{
		export_var(data, export_oldpwd);
		free(export_oldpwd);
	}
	export_newpwd = ft_strjoin("PWD=", new_pwd);
	if (export_newpwd)
	{
		export_var(data, export_newpwd);
		free(export_newpwd);
	}
	free(new_pwd);
	return (0);
}
int	check_new_dir(t_data *data, char *old_pwd, char	*target_dir)
{
	if (change_directory(data, target_dir) == 0)
	{
		if (update_environment(data, old_pwd) == -1)
		{
			if (data->free_target_dir)
				free(target_dir);
			cd_exit(data, 1, NULL, old_pwd);
			return (1);
		}
	}
	else
	{
		if (data->free_target_dir)
			free(target_dir);
		cd_exit(data, 1, NULL, old_pwd);
		return (1);
	}
	return (0);
}

void	take_dir(t_data *data, char *arg, char *old_pwd, char *target_dir)
{
	char	*home;

	if (!arg)
	{
		target_dir = get_env_value("HOME", data);
		if (!target_dir)
			cd_exit(data, 1, "cd: HOME not set\n", old_pwd);
	}
	else if (ft_strcmp(arg, "-") == 0)
	{
		target_dir = get_env_value("OLDPWD", data);
		if (!target_dir)
			cd_exit(data, 1, "cd: OLDPWD not set\n", old_pwd);
		ft_printf("%s\n", target_dir);
	}
	else if (arg[0] == '~')
	{
		home = get_env_value("HOME", data);
		if (!home)
			cd_exit(data, 1, "cd: HOME not set\n", old_pwd);
		target_dir = ft_strjoin(home, arg + 1);
		data->free_target_dir = 1;
	}
	else
		target_dir = arg;
}

void	cd(t_data *data, char *arg)
{
	char	*old_pwd;
	char	*target_dir;

	target_dir = NULL;
	data->free_target_dir = 0;
	if (data->nb_pipe != 0)
		close_input(data);
	old_pwd = get_current_directory(data);
	if (!old_pwd)
		return ;
	take_dir(data, arg, old_pwd, target_dir);
	if (data->back_in_main == 1)
		return ;
	if (check_new_dir(data, old_pwd, target_dir) == 1)
		return ;
	if (data->free_target_dir)
		free(target_dir);
	cd_exit(data, 0, NULL, old_pwd);
}
*/