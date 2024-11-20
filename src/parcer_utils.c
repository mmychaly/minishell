#include "../include/minishell.h"

static void	skip_spaces(const char *str, int *i)
{
	while (str[*i] && str[*i] == ' ')
		(*i)++;
}
// Функция возвразает строчку без кавычек
static char	*extract_quoted_token(const char *str, int *i, char quote_char)
{
	int	start;

	start = ++(*i);
	while (str[*i] && str[*i] != quote_char)
		(*i)++;
	if (str[*i] == quote_char)
		(*i)++;
	return (ft_strndup(str + start, (*i) - start - 1));
}

// Для сборки в одну строку
static char	*merge_tokens(char *first, char *second)
{
	char	*merged;

	merged = ft_strjoin(first, second);
	free(first);
	free(second);
	if (!merged)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	return (merged);
}

static char	*handle_quotes(const char *str, int *i, t_data *data, char *result)
{
	char	quote_char;
	char	*token;
	char	*expanded;

	quote_char = str[*i];
	token = extract_quoted_token(str, i, quote_char);
	if (quote_char == '"') // Для двойных кавычек обрабатываем переменные
	{
		expanded = replace_env_var(token, data);
		free(token);
		token = expanded;
	}
	if (result == NULL)
		result = token;
	else
		result = merge_tokens(result, token);
	return (result);
}

// Для подстановки переменной
static char	*handle_variable(const char *str, int *i, t_data *data,
		char *result)
{
	int		start;
	char	*var;
	char	*expanded;

	start = (*i)++;
	while (str[*i] && (ft_isalnum(str[*i]) || str[*i] == '_'))
		(*i)++;
	var = ft_strndup(str + start, *i - start);
	expanded = replace_env_var(var, data);
	free(var);
	if (result == NULL)
		result = expanded;
	else
		result = merge_tokens(result, expanded);
	return (result);
}

// Удаляет бэкслэш
static char	*handle_backslash(const char *str, int *i, char *result)
{
	char	*escaped;

	(*i)++;
	if (str[*i])
		escaped = ft_strndup(str + (*i)++, 1);
	else
		escaped = ft_strdup("");
	if (result == NULL)
		result = escaped;
	else
		result = merge_tokens(result, escaped);
	return (result);
}

//Добавляем к итоговой строке обычный текст
static char	*handle_text(const char *str, int *i, char *result)
{
	int		start;
	char	*text;

	start = *i;
	while (str[*i] && !ft_strchr(" '$\"\\", str[*i])) 		// Пока не встречаем спецсимвол
		(*i)++;
	text = ft_strndup(str + start, *i - start);
	if (result == NULL)
		result = text;
	else
		result = merge_tokens(result, text);
	return (result);
}

static char	*process_token(const char *str, int *i, t_data *data)
{
	char	*result;

	result = NULL;
	while (str[*i] && str[*i] != ' ')
	{
		if (str[*i] == '\'' || str[*i] == '"')
			result = handle_quotes(str, i, data, result);
		else if (str[*i] == '$')
			result = handle_variable(str, i, data, result);
		else if (str[*i] == '\\')
			result = handle_backslash(str, i, result);
		else
			result = handle_text(str, i, result);
	}
	return (result);
}

char	**ft_split_quotes(const char *input, t_data *data)
{
	char	**tokens;
	int		i;
	int		token_count;

	i = 0;
	token_count = 0;
	if (!input || !data)
		return (NULL);
	tokens = malloc(sizeof(char *) * (ft_strlen(input) / 2 + 2));
	if (!tokens)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	while (input[i])
	{
		skip_spaces(input, &i);
		if (input[i]) // Если есть что парсить
			tokens[token_count++] = process_token(input, &i, data);
		skip_spaces(input, &i);
	}
	tokens[token_count] = NULL;
	return (tokens);
}
