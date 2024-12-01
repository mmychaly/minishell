/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcer_utils_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artemii <artemii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 00:17:29 by artemii           #+#    #+#             */
/*   Updated: 2024/11/26 00:52:43 by artemii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	skip_spaces(const char *str, int *i)
{
	while (str[*i] && str[*i] == ' ')
		(*i)++;
}

int	validate_quotes(const char *input)
{
	int		i;
	char	quote;

	i = 0;
	quote = '\0';
	while (input[i])
	{
		if ((input[i] == '\'' || input[i] == '"') && quote == '\0')
			quote = input[i];
		else if (input[i] == quote)
			quote = '\0';
		i++;
	}
	return (quote == '\0');
}

char	*extract_quoted_token(const char *str, int *i, char quote_char)
{
	int	start;

	start = ++(*i);
	while (str[*i] && str[*i] != quote_char)
		(*i)++;
	if (str[*i] == quote_char)
		(*i)++;
	return (ft_strndup(str + start, (*i) - start - 1));
}

char	*merge_tokens(char *first, char *second)
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

char	*handle_quotes(const char *str, int *i, t_data *data, char *result)
{
	char	quote_char;
	char	*token;
	char	*expanded;

	quote_char = str[*i];
	token = extract_quoted_token(str, i, quote_char);
	if (quote_char == '"')
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
