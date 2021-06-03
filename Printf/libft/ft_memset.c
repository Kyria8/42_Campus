/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmontero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 15:34:23 by vmontero          #+#    #+#             */
/*   Updated: 2021/04/27 17:57:34 by vmontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*mid;

	mid = (unsigned char *)s;
	i = 0;
	if (n == 0)
		return (s);
	while (i < n)
	{
		*mid = (unsigned char)c;
		i++;
		if (n)
			mid++;
	}
	return (s);
}
