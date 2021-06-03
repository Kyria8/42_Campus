/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmontero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 15:48:59 by vmontero          #+#    #+#             */
/*   Updated: 2021/04/26 18:53:04 by vmontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*mid;

	i = 1;
	if (!lst)
		return (0);
	mid = lst;
	while (mid -> next != NULL)
	{
		mid = mid -> next;
		i++;
	}
	return (i);
}
