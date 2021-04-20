/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmontero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 17:34:50 by vmontero          #+#    #+#             */
/*   Updated: 2021/04/19 17:10:53 by vmontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*res;
	size_t	i;
	size_t	j;

	i = 0;
	if (!s1)
		return (0);
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
