/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmontero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 15:59:09 by vmontero          #+#    #+#             */
/*   Updated: 2021/04/13 16:37:24 by vmontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	*ft_memcpy(void *dest, const void *src, size_t num)
{
	size_t i;
	if (dest == 0 && src == 0)
		return (0);
	while (i < num)
	{
		((char *)dest)[i] = ((char *)src)[i];
		i++;
	}
	return (dest);
}

int	main(void)
{
	char a[7] = "Hola Sr";
	char end[7];
	int i = 0;
}
