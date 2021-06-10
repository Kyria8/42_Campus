/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmontero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 17:11:13 by vmontero          #+#    #+#             */
/*   Updated: 2021/06/10 18:13:55 by vmontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libftprintf.h"

int	ft_printf(const char *format, ...)
{
	va_list arg;
	int i;
	char c;
	static char *message;
	i = 0;
	va_start(arg, format);

	while (format[i])
	{
		if (format[i] != 37 && format[i + 1] != 'd')
		{
			message = ft_strjoin(message, format[i]);
			//c = (char*)va_arg(arg, char *);
			//write(1, &format[i], 1);
			//printf("%c", format[i]);
		}
		else if (format[i] == 37 && format[i + 1] == 'd')
		{
			c = va_arg(arg, int);
			message = ft_strjoin(message, format[i]);
			//printf("%d", c);
			i++;
		}
		i++;
	}
	printf("%s", message);
	va_end(arg);
	return (0);
}

int main(void)
{
	int c = 10;
	printf("Hola %d titular\n", c);
	ft_printf("Hola caracola %d titular\n", c);
	return (0);
}

