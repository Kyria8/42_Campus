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

int	ft_printf(const char *format, ...)
{
	va_list arg;
	int i;

	i = 0;
	va_start(arg, format);

	while (format[i])
	{
		if (format[i] != 37 && 
	}
	va_end(arg);
}

int main(void)
{
	printf("Hola");
	return (0);
}
