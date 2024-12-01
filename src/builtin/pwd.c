/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmychaly <mmychaly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 17:15:28 by mmychaly          #+#    #+#             */
/*   Updated: 2024/11/22 17:29:23 by mmychaly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	pwd(t_data *data)
{
	char	*buffer;
	int		len;
	int		i;

	i = 0;
	if (data->nb_pipe != 0)
		close_input(data);
	while (ft_strnstr(data->envp[i], "PWD", 3) == 0)
		i++;
	len = ft_strlen(data->envp[i]);
	len -= 3;
	buffer = malloc(sizeof(char) * len);
	if (buffer == NULL)
		if (exit_cmds_builtin(data, "Error: malloc pwd\n", 1, NULL) == 1)
			return ;
	if (getcwd(buffer, len) != NULL)
		printf("%s\n", buffer);
	else
		if (exit_cmds_builtin(data, "Error getcwd\n", 1, buffer) == 1)
			return ;
	if (exit_cmds_builtin(data, NULL, 0, buffer) == 1)
		return ;
}
