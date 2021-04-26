/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmontero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 18:22:59 by vmontero          #+#    #+#             */
/*   Updated: 2021/04/26 19:25:54 by vmontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*mid;

	if (lst)
	{
		while (*lst)
		{
			mid = (*lst)->next;
			ft_lstdelone(*lst, del);
			(*lst) = mid;
		}
	}
}
