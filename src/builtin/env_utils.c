/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmychaly <mmychaly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 01:34:04 by mmychaly          #+#    #+#             */
/*   Updated: 2024/11/25 02:40:48 by mmychaly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*replace_substring(char *str, int start, int end, char *replacement)
{
	char	*new_str;
	int		new_len;

	new_len = ft_strlen(str) - (end - start) + ft_strlen(replacement);
	new_str = malloc(new_len + 1);
	if (!new_str)
		return (NULL);
	ft_strlcpy(new_str, str, start + 1);
	if (replacement != NULL)
		ft_strlcat(new_str, replacement, new_len + 1);
	ft_strlcat(new_str, str + end, new_len + 1);
	free(str);
	return (new_str);
}

char	*check_result(t_data *data, char *result, int i)
{
	char	*status;

	if (result[i + 1] == '?')
	{
		status = ft_itoa(data->exit_status);
		result = replace_substring(result, i, i + 2, status);
		free(status);
	}
	else
		result = process_variable(result, &i, data);
	return (result);
}
