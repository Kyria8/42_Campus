/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmontero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 15:29:29 by vmontero          #+#    #+#             */
/*   Updated: 2021/04/17 18:32:48 by vmontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	len;
	char	name;

	name = c;
	len = ft_strlen(s);
	if (s == NULL)
		return (NULL);
	while (len > 0 && s[len] != name)
	{
		len--;
	}
	if (s[len] == name)
		return ((char *)s + len);
	return (NULL);
}
