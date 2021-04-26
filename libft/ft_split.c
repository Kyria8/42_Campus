/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmontero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 17:23:21 by vmontero          #+#    #+#             */
/*   Updated: 2021/04/26 16:27:44 by vmontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	ft_count(char const *s, char c)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (++i < (int)ft_strlen(s))
	{
		if (s[i] != c)
		{
			while (s[i] != c && s[i] != '\0')
				i++;
			j++;
		}
	}
	return (j);
}

char	**ft_split(char const *s, char c)
{
	char				**tab;
	int					i;
	int					j;
	unsigned int		start;

	i = -1;
	j = 0;
	if (!s)
		return (NULL);
	tab = (char **)malloc(sizeof(char *) * (ft_count(s, c) + 1));
	if (!tab)
		return (NULL);
	while (++i < (int)ft_strlen(s))
	{
		if (s[i] != c)
		{
			start = i;
			while (s[i] != c && s[i] != '\0')
				i++;
			tab[j++] = ft_substr(s, start, (i - start));
		}
	}
	tab[j] = NULL;
	return (tab);
}
/* int main(void)
{
	char	text[] = "            ";
	char	**resultado;
	resultado = ft_split(text, ' ');
	int i;

	i = 0;
	while (i < 6)
	{
		printf("%s\n", resultado[i]);
		i++;
	}
	return (0);
  }	*/
