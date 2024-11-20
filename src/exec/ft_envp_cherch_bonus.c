/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_envp_cherch_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmychaly <mmychaly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 02:22:54 by mmychaly          #+#    #+#             */
/*   Updated: 2024/10/22 04:39:34 by mmychaly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_add_symb(char **strs)
{
	char	*symb;
	char	*strs_mod;
	int		i;

	symb = "/";
	i = 0;
	while (strs[i] != NULL)
	{
		strs_mod = ft_strjoin(strs[i], symb);
		if (strs_mod == NULL)
		{
			perror("Error in ft_strjoin for ft_add_symb");
			ft_free_strs(strs);
			return ;
		}
		free(strs[i]);
		strs[i] = strs_mod;
		i++;
	}
}

void	ft_add_cmd(char **strs, char *cmd)
{
	char	*strs_mod;
	int		i;

	i = 0;
	while (strs[i] != NULL)
	{
		strs_mod = ft_strjoin(strs[i], cmd);
		if (strs_mod == NULL)
		{
			perror("Error in ft_strjoin for ft_add_cmd");
			ft_free_strs(strs);
			return ;
		}
		free(strs[i]);
		strs[i] = strs_mod;
		i++;
	}
}

char	*ft_creat_path(char **strs, char *cmd)
{
	char	*res;
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(cmd);
	while (strs[i] != NULL)
	{
		if (access(strs[i], F_OK | X_OK) == 0)
			break ;
		i++;
	}
	if (strs[i] == NULL)
	{
		write(2, cmd, len);
		write(2, ": command not found\n", 21);
		return (NULL);
	}
	res = ft_strdup(strs[i]);
	if (res == NULL)
	{
		perror("Error in ft_strdup");
		return (NULL);
	}
	return (res);
}

char	*ft_envp_cherch(char *cmd, char **envp)
{
	int		i;
	char	**strs;
	char	*res;

	i = 0;
	while (ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
	strs = ft_split(envp[i] + 5, ':');
	if (strs == NULL)
	{
		perror("Error in split");
		return (NULL);
	}
	ft_add_symb(strs);
	if (strs == NULL)
		return (NULL);
	ft_add_cmd(strs, cmd);
	if (strs == NULL)
		return (NULL);
	res = ft_creat_path(strs, cmd);
	ft_free_strs(strs);
	if (res == NULL)
		return (NULL);
	return (res);
}
