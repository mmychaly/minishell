/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artemii <artemii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 01:01:36 by artemii           #+#    #+#             */
/*   Updated: 2024/11/26 02:36:33 by artemii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	free_split(char **args)
{
	int	i;

	if (!args)
		return ;
	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}

void	free_cmd_files(t_cmd *cmd)
{
	if (cmd->input_files)
		free_split(cmd->input_files);
	if (cmd->output_files)
		free_split(cmd->output_files);
	if (cmd->append_files)
		free_split(cmd->append_files);
	if (cmd->here_doc_files)
		free_split(cmd->here_doc_files);
}

void	free_cmd_resources(t_cmd *cmd)
{
	if (cmd->cmd_arg)
		free_split(cmd->cmd_arg);
	if (cmd->input_files)
		free_split(cmd->input_files);
	if (cmd->output_files)
		free_split(cmd->output_files);
	if (cmd->append_files)
		free_split(cmd->append_files);
	if (cmd->here_doc_files)
		free_split(cmd->here_doc_files);
	if (cmd->cmd)
		free(cmd->cmd);
	if (cmd->input_file)
		free(cmd->input_file);
	if (cmd->here_doc_file)
		free(cmd->here_doc_file);
	if (cmd->output_file)
		free(cmd->output_file);
	if (cmd->append_file)
		free(cmd->append_file);
	if (cmd->here_doc_pfd != 0)
		close(cmd->here_doc_pfd);
}

void	free_data_cmd(t_data *data)
{
	int	i;

	if (!data->cmd)
		return ;
	i = 0;
	while (data->cmd[i])
	{
		free_cmd_resources(data->cmd[i]);
		free(data->cmd[i]);
		i++;
	}
	free(data->cmd);
	data->cmd = NULL;
}

void	free_all_data(t_data *data)
{
	if (data)
	{
		if (data->cmd != NULL)
			free_data_cmd(data);
		if (data->envp != NULL)
			free_split(data->envp);
		if (data->user_input != NULL)
			free(data->user_input);
		free(data);
	}
}
