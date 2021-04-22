/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmontero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 13:37:31 by vmontero          #+#    #+#             */
/*   Updated: 2021/04/22 13:52:05 by vmontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*func;

	if (!s || !f)
		return (NULL);
	func = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (func == NULL)
		return (NULL);
	i = -1;
	while (s[++i])
		func[i] = f(i, s[i]);
	func[i] = '\0';
	return (func);
}
