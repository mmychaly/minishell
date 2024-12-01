/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcer_redirections.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artemii <artemii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 00:47:10 by artemii           #+#    #+#             */
/*   Updated: 2024/12/01 17:50:33 by artemii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	**realloc_array(char **array, char *new_element)
{
	int		size;
	int		i;
	char	**new_array;

	size = 0;
	if (array)
		while (array[size])
			size++;
	new_array = malloc(sizeof(char *) * (size + 2));
	if (!new_array)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (i < size)
	{
		new_array[i] = array[i];
		i++;
	}
	new_array[size] = new_element;
	new_array[size + 1] = NULL;
	free(array);
	return (new_array);
}

int	split_token_on_redirection(char *token, char **before, char **redir,
		char **after)
{
	int	i;
	int	redir_len;

	i = 0;
	while (token[i] && !ft_strchr("<>", token[i]))
		i++;
	if (token[i])
	{
		if (i > 0)
			*before = ft_strndup(token, i);
		if (token[i + 1] && (token[i + 1] == '>' || token[i + 1] == '<'))
		{
			if (token[i + 2] && (token[i + 2] == '>' || token[i + 2] == '<'))
				return (-1);
			redir_len = 2;
		}
		else
			redir_len = 1;
		*redir = ft_strndup(token + i, redir_len);
		*after = ft_strdup(token + i + redir_len);
	}
	else
		*before = ft_strdup(token);
	return (0);
}

void	process_redirection_token(t_cmd *cmd, char *token, int *i,
		char **tokens)
{
	char	*before;
	char	*redir;
	char	*after;

	before = NULL;
	redir = NULL;
	after = NULL;
	if (!token)
		return ;
	if (split_token_on_redirection(token, &before, &redir, &after) == -1)
		return (handle_missing_after(cmd, before, "wrong  sign", after));
	handle_before_token(cmd, before);
	if (redir && (!after || *after == '\0'))
	{
		if (tokens[*i + 1])
		{
			(*i)++;
			free(after);
			after = ft_strdup(tokens[*i]);
		}
		else
			return (handle_missing_after(cmd, before, redir, after));
	}
	handle_redir_token(cmd, after, redir);
	free_temp_redir(before, after, redir);
}

void	handle_command_args(t_cmd *cmd, char **tokens, int *i)
{
	int	j;

	j = 0;
	if (!cmd || !tokens || (i && !tokens[*i]))
		return ;
	if (cmd->cmd_arg == NULL)
	{
		cmd->cmd_arg = malloc(sizeof(char *) * 100);
		if (!cmd->cmd_arg)
			return ;
		while (j < 100)
			cmd->cmd_arg[j++] = NULL;
		cmd->cmd = ft_strdup(tokens[*i]);
		if (!cmd->cmd)
		{
			free(cmd->cmd_arg);
			cmd->cmd_arg = NULL;
			return ;
		}
	}
	if (i && tokens[*i])
	{
		cmd->cmd_arg[cmd->agr_idx] = ft_strdup(tokens[*i]);
		cmd->agr_idx++;
	}
}

void	handle_here_docs(t_cmd *cmd, t_data *data)
{
	int	i;

	if (cmd->here_doc_file == NULL)
		return ;
	i = 0;
	while (cmd->here_doc_files[i] != NULL)
	{
		execution_here_doc(cmd, cmd->here_doc_files[i], data);
		if (data->back_in_main == 1)
			return ;
		i++;
	}
}
