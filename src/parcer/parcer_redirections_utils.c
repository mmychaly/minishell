/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcer_redirections_utils.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artemii <artemii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 17:40:57 by artemii           #+#    #+#             */
/*   Updated: 2024/12/01 17:50:04 by artemii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	free_temp_redir(char *before, char *redir, char *after)
{
	if (before != NULL)
		free(before);
	if (redir != NULL)
		free(redir);
	if (redir != NULL)
		free(after);
}

void	handle_missing_after(t_cmd *cmd, char *before, char *redir, char *after)
{
	ft_printf("Error: missing file for redirection '%s'\n", redir);
	cmd->error_code = 2;
	free_temp_redir(before, after, redir);
	return ;
}

void	handle_before_token(t_cmd *cmd, char *before)
{
	if (before && *before != '\0')
	{
		if (!cmd->cmd_arg)
		{
			cmd->cmd_arg = malloc(sizeof(char *) * 100);
			if (!cmd->cmd_arg)
				return ;
			ft_bzero(cmd->cmd_arg, sizeof(char *) * 100);
		}
		cmd->cmd_arg[cmd->agr_idx] = ft_strdup(before);
		cmd->agr_idx++;
	}
}

void	update_redirection(char **target_file, char ***file_array, char *token)
{
	if (*target_file)
		free(*target_file);
	*target_file = ft_strdup(token);
	*file_array = realloc_array(*file_array, ft_strdup(token));
}

void	handle_redir_token(t_cmd *cmd, char *after, char *redir)
{
	if (redir)
	{
		if (ft_strcmp(redir, "<") == 0)
		{
			cmd->pos_input = cmd->rd_idx++;
			update_redirection(&cmd->input_file, &cmd->input_files, after);
		}
		else if (ft_strcmp(redir, ">") == 0)
		{
			cmd->pos_output = cmd->rd_idx++;
			update_redirection(&cmd->output_file, &cmd->output_files, after);
		}
		else if (ft_strcmp(redir, ">>") == 0)
		{
			cmd->pos_append = cmd->rd_idx++;
			update_redirection(&cmd->append_file, &cmd->append_files, after);
		}
		else if (ft_strcmp(redir, "<<") == 0)
		{
			cmd->pos_here_doc = cmd->rd_idx++;
			update_redirection(&cmd->here_doc_file, &cmd->here_doc_files,
				after);
		}
	}
}
