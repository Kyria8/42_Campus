/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmontero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 17:11:13 by vmontero          #+#    #+#             */
/*   Updated: 2021/06/03 18:56:03 by vmontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libftprintf.h"
#include <string.h>

void	ft_charmanage(va_list arg, t_flags *marker)
{
	char c;
	int i;

	i = 0;
	c = va_arg(arg, int);
	if (marker ->minus == 1)
	{
		write (1, &c, 1);
		i++;
		ft_countweight (marker, i);
		marker ->weight = 0;
	}
	else if (marker ->weight > 0)
	{
		ft_countweight (marker, i);
		write (1, &c, 1);
	}
	write (1, &c, 1);
}

int	ft_printf(const char *format, ...)
{
	va_list arg;
	int i;
	
	i = 0;
	va_start(arg, format);

	while (format[i])
	{
		
		if (format[i] == 37)
		{
			//c = va_arg(arg, int);
			i++;
			i += ft_datatype(&format[i], arg);

			//printf("Pavon dice.....Donde esta i %c\n", format[i]);
			i++;
		}
		write (1, &format[i], 1);
		i++;
	}
	va_end(arg);
	return (0);
}

int main(void)
{
	int c = 10;
	int p = 25;
	char ch = 'a';
	printf("Hola... %c ...titular\n", ch);
	ft_printf("Si escribo despues, se rompe.... %c\n", ch);
	return (0);
}
