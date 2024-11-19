/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_var_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artemii <artemii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 00:06:31 by artemii           #+#    #+#             */
/*   Updated: 2024/11/20 00:15:47 by artemii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*extract_var_name(const char *str)
{
	int	i;

	i = 0;
	if (str[i] == '$')
		i++;
	while (str[i] && (ft_isalnum(str[i]) || str[i] == '_')) // Считаем, пока не встретится недопустимый символ
		i++;
	return (ft_substr(str, 1, i - 1)); // Возвращаем имя переменной без '$'
}

// Проверка на существование переменной в окружении (без получения её значения)
int	env_var_exists(const char *name, t_data *data)
{
	int	len;
	int	i;

	len = ft_strlen(name);
	i = 0;
	while (data->envp[i] != NULL)
	{
		if (ft_strncmp(data->envp[i], name, len) == 0 && data->envp[i][len] == '=')
			return (1); // Переменная найдена
		i++;
	}
	return (0); // Переменная не найдена
}


char	*replace_substring(char *str, int start, int end, char *replacement)
{
	char	*new_str;
	int		new_len;

	new_len = ft_strlen(str) - (end - start) + ft_strlen(replacement);
	new_str = malloc(new_len + 1);
	if (!new_str)
		return (NULL);
	ft_strlcpy(new_str, str, start + 1); // Копируем часть строки до начала замены
	if (replacement != NULL)
		ft_strlcat(new_str, replacement, new_len + 1);
	ft_strlcat(new_str, str + end, new_len + 1); // Добавляем оставшуюся часть строки после замены
	free(str);                                  
	return (new_str);
}


char	*get_env_value(char *name, t_data *data)
{
	int	len;
	int	i;

	len = ft_strlen(name);
	i = 0;
	while (data->envp[i] != NULL)
	{
		// Ищем совпадение имени переменной до символа '='
		if (ft_strncmp(data->envp[i], name, len) == 0 && data->envp[i][len] == '=')
			return (data->envp[i] + len + 1); // Возвращаем указатель на значение после '='
		i++;
	}
	return (NULL); // Переменная не найдена
}

char	*process_variable(char *result, int *i, t_data *data)
{
	char	*var_name;
	char	*var_value;
	int		end;

	var_name = extract_var_name(result + *i); // Извлекаем имя переменной
	if (var_name)
	{
		if (env_var_exists(var_name, data)) // Проверяем существование переменной в data->envp
		{
			var_value = get_env_value(var_name, data); // Получаем значение переменной
			if (var_value == NULL) // На случай, если переменная найдена, но значение пустое
				var_value = "";
			result = replace_substring(result, *i, *i + ft_strlen(var_name) + 1,
					var_value);
			*i += ft_strlen(var_value); // Сдвигаем индекс на длину значения
		}
		else
		{
			end = *i + ft_strlen(var_name) + 1; // Если переменной нет, просто удаляем её из строки
			ft_memmove(result + *i, result + end, ft_strlen(result + end) + 1);
		}
		free(var_name);
	}
	return (result);
}

// Функция,которая заменяет переменные окружения на их значения
char	*replace_env_var(char *input, t_data *data)
{
	char	*result;
	int		i;
	char *status;

    i = 0;
    result = ft_strdup(input);
    if (!result)
        return (NULL);
    while (result[i] != '\0')
    {
        if (result[i] == '\\')  // Если найден символ `\`
        {
            i++;  // Пропускаем его
            continue;
        }
        if (result[i] == '$')  // Обрабатываем переменные окружения
         {   
			if (result[i + 1] == '?') // Проверяем на `$?`
            {
                status = ft_itoa(data->exit_status); // Конвертируем exit_status в строку
                result = replace_substring(result, i, i + 2, status); // Заменяем `$?` на статус
                free(status);
            }
            else
                result = process_variable(result, &i, data); // Стандартная обработка переменных
			}
        else
            i++;
    }
	return (result);
}

