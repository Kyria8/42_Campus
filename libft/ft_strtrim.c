/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmontero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 19:38:45 by vmontero          #+#    #+#             */
/*   Updated: 2021/04/22 17:22:58 by vmontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	ft_cutinit(char const *s1, char const *set)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1 && set[j] != '\0')
	{
		if (s1[i] == set[j])
		{
			i++;
			j = 0;
		}
		else if (s1[i] != set[j])
			j++;
	}
	return (i);
}

static int	ft_cutend(char const *s1, char const *set)
{
	size_t	len;
	size_t	j;

	len = ft_strlen(s1) - 1;
	j = 0;
	while (s1 && set[j] != '\0')
	{
		if (s1[len] == set[j])
		{
			len--;
			j = 0;
		}
		else if (s1[len] != set[j])
			j++;
	}
	return (len);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char				*res;
	unsigned int		init;
	unsigned int		end;
	int					len;

	res = NULL;
	if (s1)
	{
		init = ft_cutinit(s1, set);
		end = ft_cutend(s1, set);
		len = end - init + 1;
		if (len >= 0)
		{
			res = ft_substr(s1, init, len);
			res[len++] = '\0';
		}
		else
		{
			len = 0;
			return (ft_substr(s1, init, len));
		}
	}
	else
		return (NULL);
	return (res);
}
