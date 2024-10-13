/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artemii <artemii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 01:23:19 by artemii           #+#    #+#             */
/*   Updated: 2024/10/13 23:47:22 by artemii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	handle_redirections_and_pipes(t_command *cmd, char **tokens, int *i)
{
	if (ft_strcmp(tokens[*i], "<") == 0) // Если найден оператор ввода
	{
		*i += 1;
		cmd->input_file = ft_strdup(tokens[*i]);
		// Сохраняем имя файла для ввода
	}
	else if (ft_strcmp(tokens[*i], ">") == 0) // Если найден оператор вывода
	{
		*i += 1;
		cmd->output_file = ft_strdup(tokens[*i]);
		// Сохраняем имя файла для вывода
	}
	else if (ft_strcmp(tokens[*i], ">>") == 0)
	// Если найден оператор добавления
	{
		*i += 1;
		cmd->output_file = ft_strdup(tokens[*i]);
		// Сохраняем имя файла для добавления
		cmd->append = 1; // Устанавливаем флаг append
	}
	else if (ft_strcmp(tokens[*i], "<<") == 0) // Если найден оператор here_doc
	{
		*i += 1;
		cmd->args = malloc(sizeof(char *) * 2);
		// Для here_doc нужен только ограничитель
		cmd->args[0] = ft_strdup("here_doc");
		cmd->args[1] = ft_strdup(tokens[*i]); // Ограничитель для here_doc
		cmd->here_doc = 1;                    // Устанавливаем флаг here_doc
	}
	else if (ft_strcmp(tokens[*i], "|") == 0) // Если найден пайп
		cmd->is_pipe = 1;                     // Устанавливаем флаг пайпа
}

void	handle_arguments(t_command *cmd, char **tokens, int *i, int *arg_idx)
{
	cmd->args[*arg_idx] = ft_strdup(tokens[*i]); // Сохраняем аргумент
	*arg_idx += 1;
}

t_command	*parse_input(char *input)
{
	t_command	*cmd;
	int			i;
	int			arg_idx;

	cmd = malloc(sizeof(t_command));
	char **tokens = ft_split(input, ' '); // Разбиваем строку на токены
	i = 0;
	arg_idx = 0;
	// Инициализация полей структуры
	ft_memset(cmd, 0, sizeof(t_command));
	cmd->args = malloc(sizeof(char *) * 100); // Максимум 100 аргументов
	// Обработка каждого токена
	while (tokens[i] != NULL)
	{
		if (ft_strcmp(tokens[i], "<") == 0 || ft_strcmp(tokens[i], ">") == 0
			|| ft_strcmp(tokens[i], ">>") == 0 || ft_strcmp(tokens[i],
				"<<") == 0 || ft_strcmp(tokens[i], "|") == 0)
			handle_redirections_and_pipes(cmd, tokens, &i);
		// Обрабатываем редиректы и пайпы
		else
			handle_arguments(cmd, tokens, &i, &arg_idx);
		// Обрабатываем обычные аргументы
		i++;
	}
	cmd->args[arg_idx] = NULL; // Завершаем массив аргументов
	free_split(tokens);        // Освобождаем токены
	return (cmd);
}

// Подсчет количества пайпов в строке
// static int count_pipes(char *input)
//{
//    int count = 0;
//    int i = 0;
//    while (input[i])
//    {
//        if (input[i] == '|')
//            count++;
//        i++;
//    }
//    return (count);
//}

// Разбор строк с пайпами и их аргументами
t_command	*parse_pipeline(char *input)
{
	t_command	*cmd;
	char		**tokens;
	int			i;
	int			arg_idx;

	i = 0;
	arg_idx = 0;
	tokens = ft_split(input, ' ');   // Разбиваем строку на токены по пробелам
	cmd = malloc(sizeof(t_command)); // Выделяем память для структуры команды
	if (!cmd)
		return (NULL);
	// Инициализация полей структуры
	ft_memset(cmd, 0, sizeof(t_command));
	cmd->args = malloc(sizeof(char *) * 100); // Выделяем память для аргументов
	if (!cmd->args)
		return (NULL);
	// Обработка каждого токена
	while (tokens[i] != NULL)
	{
		if (ft_strcmp(tokens[i], "<") == 0 || ft_strcmp(tokens[i], ">") == 0
			|| ft_strcmp(tokens[i], ">>") == 0 || ft_strcmp(tokens[i],
				"<<") == 0 || ft_strcmp(tokens[i], "|") == 0)
			handle_redirections_and_pipes(cmd, tokens, &i);
		// Обрабатываем редиректы и пайпы
		else
			handle_arguments(cmd, tokens, &i, &arg_idx);
		i++;
	}
	cmd->args[arg_idx] = NULL; // Завершаем массив аргументов
	free_split(tokens);        // Освобождаем временный массив строк
	return (cmd); // Возвращаем заполненную команду
}

/*
char	**parse_input(char *input)
{
	char	**args;
	char	*token;
	int		i;

	i = 0;
	// Выделяем память для аргументов (предположим,
		что не более 100 аргументов)
	args = malloc(sizeof(char *) * 100);
	if (!args)
		return (NULL);
	// Разбиваем строку по пробелам
	token = strtok(input, " ");
	while (token != NULL)
	{
		args[i] = ft_strdup(token);
			// используем strdup для копирования строки
		i++;
		token = strtok(NULL, " ");
	}
	args[i] = NULL; // Завершаем массив аргументов NULL
	return (args);
}
char	***parse_pipeline(char *input)
{
	char	**commands;
	char	***parsed_commands;
	int		i;

	commands = ft_split(input, '|');
	parsed_commands = malloc(sizeof(char **) * (count_pipes(input) + 2));
	if (!parsed_commands)
		return (NULL);
	i = 0;
	while (commands[i])
	{
		parsed_commands[i] = parse_input(commands[i]);
		i++;
	}
	parsed_commands[i] = NULL;
	free_split(commands);
	return (parsed_commands);
}
*/