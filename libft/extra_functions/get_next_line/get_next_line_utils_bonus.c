/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artemii <artemii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 14:08:45 by azakharo          #+#    #+#             */
/*   Updated: 2024/10/25 00:32:26 by artemii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strchr(const char *str, int c)
{
	unsigned char	ch;

	ch = (unsigned char)c;
	while (*str != '\0')
	{
		if (*str == ch)
			return ((char *)str);
		str++;
	}
	if (ch == '\0')
	{
		return ((char *)str);
	}
	return (NULL);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (*str++)
		i++;
	return (i);
}

char	*ft_strdup(const char *src)
{
	int		i;
	int		length;
	char	*data;

	length = ft_strlen(src);
	data = (char *)malloc((length + 1) * sizeof(char));
	if (!data)
		return (0);
	i = 0;
	while (i < length)
	{
		data[i] = src[i];
		i++;
	}
	data[length] = '\0';
	return (data);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result_string;
	int		total_len;
	size_t	i;
	size_t	j;

	total_len = ft_strlen(s1) + ft_strlen(s2);
	result_string = malloc(sizeof(char) * (total_len + 1));
	if (!result_string)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
		result_string[j++] = s1[i++];
	i = 0;
	while (s2[i] != '\0')
		result_string[j++] = s2[i++];
	result_string[j] = '\0';
	return (result_string);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substring;
	size_t	i;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (len > s_len - start)
		len = s_len - start;
	substring = malloc(sizeof(char) * (len + 1));
	if (!substring)
		return (NULL);
	i = 0;
	while (i < len)
	{
		substring[i] = s[start + i];
		i++;
	}
	substring[i] = '\0';
	return (substring);
}
