/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmontero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 13:21:30 by vmontero          #+#    #+#             */
/*   Updated: 2021/04/22 18:13:40 by vmontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	int		mix;

	i = 0;
	j = 0;
	mix = 0;
	while (s[i])
	{
		if (i >= start && j < len)
		{
			mix++;
			j++;
		}
		i++;
	}
	return (mix);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	i;
	size_t	j;

	j = 0;
	if (!s)
		return (NULL);
	res = (char *)malloc(sizeof(char) * (ft_count(s, start, len) + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (s[i])
	{
		if (i >= start && j < len)
		{
			res[j] = s[i];
			j++;
		}
		i++;
	}
	res[j] = '\0';
	return (res);
}
