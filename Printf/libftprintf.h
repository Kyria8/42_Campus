/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmontero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 17:24:55 by vmontero          #+#    #+#             */
/*   Updated: 2021/06/03 17:04:21 by vmontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

#include "libft/libft.h"
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

# define TYPE "cspdiuxX%"
# define FLAGS "-0."

typedef struct s_options
{
    int weight;
    int minus;
    int zero;
    int point;
    int negative;
    int is_null;

} t_flags;

void	ft_charmanage(va_list arg, t_flags *marker);
void	ft_datadistribution(const char *format, va_list arg, t_flags *marker);
int ft_datatype(const char *format, va_list arg);
t_flags	*ft_initflags(t_flags *marker);
void	ft_flagscheck(const char *format, va_list arg);
void ft_stringmanage(va_list arg, t_flags *marker);
void ft_countweight (t_flags *marker, int i);
int	ft_printf(const char *, ...);




#endif
