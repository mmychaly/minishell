#include "../include/minishell.h"

void	free_split(char **args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}

// Обработка редиректов и установка позиций
void	handle_redirection(t_cmd *cmd, char **tokens, int *i, int *redir_position)
{
	if (ft_strcmp(tokens[*i], "<") == 0) // Входной редирект
	{
		*i += 1;
		cmd->input_file = ft_strdup(tokens[*i]);
		cmd->pos_input = (*redir_position)++;
	}
	else if (ft_strcmp(tokens[*i], ">") == 0)
	{
		*i += 1;
		cmd->output_file = ft_strdup(tokens[*i]);
		cmd->pos_output = (*redir_position)++;
	}
	else if (ft_strcmp(tokens[*i], ">>") == 0)
	{
		*i += 1;
		cmd->append_file = ft_strdup(tokens[*i]);
		cmd->pos_append = (*redir_position)++;
	}
	else if (ft_strcmp(tokens[*i], "<<") == 0)
	{
		*i += 1;
		cmd->here_doc_file = ft_strdup(tokens[*i]);
		cmd->pos_here_doc = (*redir_position)++;
	}
}

void	handle_command_args(t_cmd *cmd, char **tokens, int *i, int *arg_idx)
{
	if (cmd->cmd_arg == NULL)
	{	cmd->cmd_arg = malloc(sizeof(char *) * 100);
		cmd->cmd = ft_strdup(tokens[*i]);
	}
	cmd->cmd_arg[(*arg_idx)++] = ft_strdup(tokens[*i]); 
}

void	parse_single_command(t_cmd *cmd, char *input)
{
	int		i;
	int		arg_idx;
	int		redir_position;
	char	**tokens;

	i = 0;
	arg_idx = 0;
	redir_position = 1; // Для отслеживания порядка редиректов
	tokens = ft_split_quotes(input);
	while (tokens[i] != NULL)
	{
		if (ft_strcmp(tokens[i], "<") == 0 || ft_strcmp(tokens[i], ">") == 0 ||
			ft_strcmp(tokens[i], ">>") == 0 || ft_strcmp(tokens[i], "<<") == 0)
			handle_redirection(cmd, tokens, &i, &redir_position);
		else
			handle_command_args(cmd, tokens, &i, &arg_idx);
		i++;
	}
	cmd->cmd_arg[arg_idx] = NULL;
	free_split(tokens);
}

// Парсинг пайплайна команд
void	parse_pipeline(t_data *data, char *input)
{
	char	**command_tokens;
	int		cmd_count;
	int		i;

	cmd_count = 0;
	i = 0;
	command_tokens = ft_split(input, '|');
	while (command_tokens[cmd_count] != NULL)
		cmd_count++;
	data->cmd = malloc(sizeof(t_cmd *) * (cmd_count + 1));
	data->nb_pipe = cmd_count - 1; // Количество пайпов = команд - 1

	while (i < cmd_count)
	{
		data->cmd[i] = malloc(sizeof(t_cmd));
		if (!data->cmd[i])
		{
			perror("malloc failed");
			return ;
		}
		ft_memset(data->cmd[i], 0, sizeof(t_cmd));
		parse_single_command(data->cmd[i], command_tokens[i]);
		i++;
	}
	data->cmd[cmd_count] = NULL;
	free_split(command_tokens);
}
