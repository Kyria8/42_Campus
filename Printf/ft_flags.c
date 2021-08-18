#include <stdio.h>
#include "libftprintf.h"
#include <string.h>

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