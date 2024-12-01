/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_var_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmychaly <mmychaly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 00:06:31 by artemii           #+#    #+#             */
/*   Updated: 2024/11/25 01:45:14 by mmychaly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*extract_var_name(const char *str)
{
	int	i;

	i = 0;
	if (str[i] == '$')
		i++;
	while (str[i] && (ft_isalnum(str[i]) || str[i] == '_'))
		i++;
	return (ft_substr(str, 1, i - 1));
}

int	env_var_exists(const char *name, t_data *data)
{
	int	len;
	int	i;

	len = ft_strlen(name);
	i = 0;
	while (data->envp[i] != NULL)
	{
		if (ft_strncmp(data->envp[i], name, len) == 0
			&& data->envp[i][len] == '=')
			return (1);
		i++;
	}
	return (0);
}

char	*get_env_value(char *name, t_data *data)
{
	int	len;
	int	i;

	len = ft_strlen(name);
	i = 0;
	while (data->envp[i] != NULL)
	{
		if (ft_strncmp(data->envp[i], name, len) == 0
			&& data->envp[i][len] == '=')
			return (data->envp[i] + len + 1);
		i++;
	}
	return (NULL);
}

char	*process_variable(char *result, int *i, t_data *data)
{
	char	*var_name;
	char	*var_value;
	int		end;

	var_name = extract_var_name(result + *i);
	if (var_name)
	{
		if (env_var_exists(var_name, data))
		{
			var_value = get_env_value(var_name, data);
			if (var_value == NULL)
				var_value = "";
			result = replace_substring(result, *i, *i + ft_strlen(var_name) + 1,
					var_value);
			*i += ft_strlen(var_value);
		}
		else
		{
			end = *i + ft_strlen(var_name) + 1;
			ft_memmove(result + *i, result + end, ft_strlen(result + end) + 1);
		}
		free(var_name);
	}
	return (result);
}

char	*replace_env_var(char *input, t_data *data)
{
	char	*result;
	int		i;

	i = 0;
	result = ft_strdup(input);
	if (!result)
		return (NULL);
	while (result[i] != '\0')
	{
		if (result[i] == '\\')
		{
			i++;
			continue ;
		}
		if (result[i] == '$')
			result = check_result(data, result, i);
		else
			i++;
	}
	return (result);
}
