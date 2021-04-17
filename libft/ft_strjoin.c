/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmontero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 20:06:02 by vmontero          #+#    #+#             */
/*   Updated: 2021/04/17 20:41:57 by vmontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*res;
	
	if (s1 && s2)
	{
		len = ft_strlen(s1) + ft_strlen(s2);
		res = (char *)malloc(sizeof(char) * (len + 1));
		if (res)
		{
			ft_strlcpy(res, (char *)s1, len);
			ft_strlcat(res, (char *)s2, len);
			return (res);
		}
		else
			return (NULL);
	}
	return (NULL);
}

/*int main(void)
{
	char text1[] = "Hola! ";
	char text2[] = "primos";
	printf("%s", ft_strjoin(text1, text2));
	return (0);
}*/
