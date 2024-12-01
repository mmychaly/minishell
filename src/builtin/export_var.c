/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_var.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmychaly <mmychaly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 01:50:30 by mmychaly          #+#    #+#             */
/*   Updated: 2024/11/25 02:35:09 by mmychaly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static char	*get_key(const char *input)
{
	char	*equal_pos;

	equal_pos = ft_strchr(input, '=');
	if (!equal_pos)
		return (NULL);
	return (ft_substr(input, 0, equal_pos - input));
}

int	update_or_add_var(t_data *data, char *new_var, char *key)
{
	int		i;
	char	**new_envp;

	if (!key || !new_var)
		return (-1);
	i = 0;
	while (data->envp[i])
	{
		if (ft_strncmp(data->envp[i], key, ft_strlen(key)) == 0
			&& data->envp[i][ft_strlen(key)] == '=')
		{
			free(data->envp[i]);
			data->envp[i] = new_var;
			return (0);
		}
		i++;
	}
	new_envp = ft_realloc(data->envp, sizeof(char *) * (i + 1), sizeof(char *)
			* (i + 2));
	if (!new_envp)
		return (-1);
	new_envp[i] = new_var;
	new_envp[i + 1] = NULL;
	data->envp = new_envp;
	return (0);
}

static void	handle_export_error(t_data *data, char *key, char *new_var)
{
	if (key)
		free(key);
	if (new_var)
		free(new_var);
	ft_printf("export has a wrong identifier\n");
	if (data->nb_pipe == 0)
	{
		data->back_in_main = 1;
		data->exit_status = 1;
	}
	else
	{
		close(1);
		free_all_data(data);
		exit(1);
	}
}

static void	export_key_value(t_data *data, const char *input)
{
	char	*key;
	char	*new_var;

	key = get_key(input);
	if (!key || !ft_isalpha(key[0]))
		return (handle_export_error(data, key, NULL));
	new_var = ft_strdup(input);
	if (!new_var || update_or_add_var(data, new_var, key) == -1)
		return (handle_export_error(data, key, new_var));
	free(key);
	if (data->nb_pipe == 0)
	{
		data->back_in_main = 1;
		data->exit_status = 0;
		return ;
	}
	close(1);
	free_all_data(data);
	exit(0);
}

void	export_var(t_data *data, const char *input)
{
	if (data->nb_pipe != 0)
		close_input(data);
	if (!input)
		print_env(data);
	else
		export_key_value(data, input);
}
