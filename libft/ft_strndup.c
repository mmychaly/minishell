/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artemii <artemii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 01:50:19 by artemii           #+#    #+#             */
/*   Updated: 2024/10/15 01:51:28 by artemii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *src, size_t n)
{
	size_t	i;
	char	*data;

	data = (char *)malloc((n + 1) * sizeof(char));
	if (!data)
		return (0);
	i = 0;
	while (i < n && src[i] != '\0')
	{
		data[i] = src[i];
		i++;
	}
	data[i] = '\0';
	return (data);
}
