/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmontero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 17:50:27 by vmontero          #+#    #+#             */
/*   Updated: 2021/04/27 17:50:20 by vmontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(long int n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		n = n * -1;
		i++;
	}
	if (n == 0)
		i++;
	while (n > 0)
	{	
		n = n / 10;
		i++;
	}
	return (i);
}

static char	*ft_conver(long int n, char *res, int len)
{
	res[len] = '\0';
	if (n == 0)
	{
		res[0] = '0';
	}
	while (n > 0)
	{
		res[--len] = n % 10 + 48;
		n = n / 10;
	}
	return (res);
}

char	*ft_itoa(int n)
{
	char		*res;
	long int	num;
	int			len;

	num = n;
	len = ft_count(num);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (res)
	{
		if (num < 0)
		{
			num = num * -1;
			res[0] = '-';
		}
		if (num >= 0)
			ft_conver(num, res, len);
	}
	return (res);
}
