/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmontero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 18:59:19 by vmontero          #+#    #+#             */
/*   Updated: 2021/04/27 17:04:04 by vmontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*init;
	t_list	*mid;

	if (lst)
	{
		mid = lst;
		init = ft_lstnew(f(mid->content));
		if (init == NULL)
			return (NULL);
		mid = mid ->next;
		while (mid)
		{
			new = ft_lstnew(f(mid->content));
			if (new == NULL)
			{
				ft_lstclear(&init, del);
				return (NULL);
			}
			ft_lstadd_back(&init, new);
			mid = mid -> next;
		}
		return (init);
	}
	return (NULL);
}
