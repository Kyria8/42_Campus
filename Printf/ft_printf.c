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

	c = va_arg(arg, int);
	write (1, &c, 1);
}
void	ft_datadistribution(const char *format, va_list arg, t_flags *marker)
{
	if (format[0] == 'c')
		ft_charmanage(arg, marker);
}
t_flags	*ft_initflags(t_flags *marker)
{
	marker ->minus = 0;
	marker ->point = -1;
	marker ->weight = 0;
	marker ->zero = 0;
	marker ->negative = 0;
	marker ->is_null = 0;

	return (marker);
}
void	ft_flagscheck(const char *format, va_list arg)
{
	t_flags *marker;
	int i;

	i = 0;
	//VA BUSCANDO SI HAY PUNTO, Y SI ENCUENTRA EL PUNTO, BUSCA SI HAY NUMERO, PARA MARCAR LA PRECISION, TANTO EN STRING COMO EN NUMEROS.SI NO HAY NUMERO, LA PRECISION ES 0.
	ft_initflags(marker);
	while (format[i] != TYPE)
	{
		if (format[i] == '-')
			marker ->minus++;
		else if (format[i] == '0')
			marker ->zero++;
		else if (format[i] > 0)
			marker ->weight = format[i];
		else if (format[i] == '.')
		{
			if (format[++i] > 0)
				{
					marker ->point = 1;
					marker ->weight = format[i];
				}
			else
				marker ->point = 0;
		}
		else
			marker ->is_null++;
		i++;
	}
	ft_datadistribution(&format[i], arg, marker);
}

int ft_datatype(const char *format, va_list arg)
{
	t_flags *marker;
	int	i;

	i = 0;
	if (strchr(TYPE, format[i]) != 0)
		ft_datadistribution(&format[i], arg, marker);
	else if (strchr(FLAGS, format[i] != 0))
	//	FUNCION QUE CHECKEA QUE FLGS HAY ACTIVOS Y ENTRA EN TIPO DE DATO
		ft_flagscheck(&format[i], arg);
	// while (format[i])
	// {
	// 	if (strchr(TYPE, format[i]) != 0)
	// 		printf("%d", va_arg(arg, int));
	// 	i++;
	// }

	return (i);
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
