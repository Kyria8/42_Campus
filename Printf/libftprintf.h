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

int	ft_printf(const char *, ...);



#endif
