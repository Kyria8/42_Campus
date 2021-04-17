/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmontero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 17:05:34 by vmontero          #+#    #+#             */
/*   Updated: 2021/04/16 17:33:27 by vmontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	char	*res;

	res = malloc(count * size);
	if (!res)
		return (0);
	i = 0;
	while (i <= count * size)
	{
		(res[i] = 0);
		 i++;
	}
	return (res);
}
