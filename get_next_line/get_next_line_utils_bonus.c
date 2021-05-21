/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmontero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 16:02:03 by vmontero          #+#    #+#             */
/*   Updated: 2021/05/21 16:03:00 by vmontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	result = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!result)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		result[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		result[i + j] = s2[j];
		j++;
	}
	result[i + j] = '\0';
	return (result);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	size_t	len;

	len = ft_strlen(s);
	i = 0;
	if (!s)
		return (NULL);
	while (i < len + 1)
	{
		if (s[i] == (unsigned char)c)
			return ((char *)s + i + 1);
		i++;
	}
	return (0);
}

char	*ft_strdup(const char *s1)
{
	char	*res;
	size_t	i;
	size_t	j;

	i = 0;
	while (s1[i])
		i++;
	res = malloc(i + 1);
	j = 0;
	if (res != '\0')
	{
		while (s1[j])
		{
			res[j] = s1[j];
			j++;
		}
		res[j] = '\0';
		return (res);
	}
	return (0);
}

char *ft_substr(char const *s, unsigned int start, size_t len)
{
char *str;
size_t i;
size_t j;

if (!s)
return (0);
i = -1;
j = 0;
while (s[++i] != '\0')
{
if (i >= start && j < len)
j++;
}
str = malloc(sizeof(char) * j + 1);
if (!str)
return (0);
j = 0;
i = 0;
while (s[j] != '\0')
{
if (j >= start && i < len)
str[i++] = s[j];
j++;
}
str[i] = '\0';
return (str);
}
