/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmontero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 18:35:15 by vmontero          #+#    #+#             */
/*   Updated: 2021/04/25 19:12:06 by vmontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

t_list	*ft_lstnew(void *content)
{
	t_list	*new_element;
	
	new_element = malloc(sizeof(t_list));
	if (!new_element || !content)
		return (NULL);
	new_element -> content = content;
	new_element -> next = NULL;
	return (new_element);
}

int main(void)
{
	char	text[] = "lorem ipsum dolor sit";
	t_list *element;
	element = ft_lstnew((void *)text);
	printf("\n%s\n", element -> content);
	return (0);
}
