/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 10:12:11 by tmoumni           #+#    #+#             */
/*   Updated: 2023/05/05 12:05:32 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *str)
{
	int	length;

	length = 0;
	if (!str)
		return (0);
	while (str[length])
		length++;
	return (length);
}

char	*ft_strdup(const char *s)
{
	char	*ptr;
	int		count;

	count = 0;
	ptr = (char *)malloc((ft_strlen((char *)s) + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	while (count < ft_strlen((char *)s))
	{
		ptr[count] = s[count];
		count++;
	}
	ptr[count] = '\0';
	return (ptr);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	count;
	size_t	s1len;
	size_t	s2len;

	count = 0;
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	str = (char *)malloc((s1len + s2len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (count < s1len + s2len)
	{
		if (count < s1len)
			str[count] = s1[count];
		else
			str[count] = s2[count - s1len];
		count++;
	}
	str[count] = '\0';
	return (free((void *)s1), str);
}

char	*ft_strjoinnw(char const *s1, char const *s2)
{
	char	*str;
	size_t	count;
	size_t	s1len;
	size_t	s2len;

	count = 0;
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	str = (char *)malloc((s1len + s2len) * sizeof(char));
	if (!str)
		return (NULL);
	while (count < s1len + s2len)
	{
		if (count < s1len)
			str[count] = s1[count];
		else
			str[count] = s2[count - s1len];
		count++;
	}
	if (str[count - 1] == '\n')
		str[count - 1] = '\0';
	else
		str[count] = '\0';
	return (free((void *)s1), free((void *)s2), str);
}
