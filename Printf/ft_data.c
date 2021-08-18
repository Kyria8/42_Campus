#include <stdio.h>
#include "libftprintf.h"
#include <string.h>

void	ft_datadistribution(const char *format, va_list arg, t_flags *marker)
{
	if (format[0] == 'c')
		ft_charmanage(arg, marker);
    else if (format[0] == 's')
        ft_stringmanage(arg, marker);
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
void ft_countweight (t_flags *marker, int i)
{
    if (marker ->zero == 0)
    {
        while (i < marker ->weight)
		    {
			    write (1, " ", 1);
			    i++;
		    }
    }
    else if (marker ->zero == 1)
    {
        while (i < marker ->weight)
        {
            write (1, "0", 1);
            i++;
        }
    }
}
void ft_printchar(char *aux, t_flags *marker)
{
    int i;

    i = 0;
    while (aux[i])
    {
        write (1, &aux[i], 1);
        i++;
    }
}

