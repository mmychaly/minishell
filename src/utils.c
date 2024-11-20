
#include "../include/minishell.h"

//void free_parsed_commands(t_command **commands)
//{
//    int i = 0;
//    int j;

//    // Освобождаем каждую команду в массиве
//    while (commands[i])
//    {
//        // Освобождаем аргументы команды
//        j = 0;
//        while (commands[i]->args[j])
//        {
//            free(commands[i]->args[j]);
//            j++;
//        }
//        free(commands[i]->args);  // Освобождаем сам массив аргументов

//        // Освобождаем файлы для редиректа, если они существуют
//        if (commands[i]->input_file)
//            free(commands[i]->input_file);
//        if (commands[i]->output_file)
//            free(commands[i]->output_file);

//        // Освобождаем саму структуру команды
//        free(commands[i]);
//        i++;
//    }
//    free(commands);  // Освобождаем массив структур
//}

char	*find_command(char *cmd, char **envp)
{
	char	**paths;
	char	*path;
	char	*cmd_path;
	int		i;

	while (*envp && ft_strncmp("PATH=", *envp, 5) != 0)
		envp++;
	if (!*envp)
		return (NULL);
	paths = ft_split(*envp + 5, ':');
	i = -1;
	while (paths[++i])
	{
		path = ft_strjoin(paths[i], "/");
		cmd_path = ft_strjoin(path, cmd);
		free(path);
		if (access(cmd_path, F_OK | X_OK) == 0)
		{
			free_split(paths);
			return (cmd_path);
		}
		free(cmd_path);
	}
	free_split(paths);
	return (NULL);
}
void	error_exit(const char *message)
{
	perror(message);
	exit(EXIT_FAILURE);
}

static void skip_spaces(const char *str, int *i)
{
    while (str[*i] && str[*i] == ' ')
        (*i)++;
}

static char *get_token_in_quotes(const char *str, int *i, char quote_char)
{
    int start = ++(*i);
    while (str[*i] && str[*i] != quote_char)
        (*i)++;
    if (str[*i] == quote_char)
        (*i)++;
    
    char *token = ft_strndup(str + start, (*i) - start - 1);
    return token;
}

char **ft_split_quotes(const char *input)
{
    char **tokens = malloc(sizeof(char *) * (strlen(input) / 2 + 2)); // например половина строки + запас
    int i = 0;
    int token_count = 0;

    while (input[i])
    {
        skip_spaces(input, &i);

        if (input[i] == '\'' || input[i] == '"')  // Если начинается с кавычки
        {
            char quote_char = input[i];
            tokens[token_count++] = get_token_in_quotes(input, &i, quote_char);
        }
        else  // Если это обычный токен без кавычек
        {
            int start = i;
            while (input[i] && input[i] != ' ' && input[i] != '\'' && input[i] != '"')
                i++;
            tokens[token_count++] = ft_strndup(input + start, i - start);
        }

        skip_spaces(input, &i);
    }
    tokens[token_count] = NULL;  // Завершаем массив токенов
    return tokens;
}
