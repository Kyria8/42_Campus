/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmontero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 19:13:52 by vmontero          #+#    #+#             */
/*   Updated: 2021/04/25 19:30:16 by vmontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft"

void	ft_lstadd_front(t_list **alst, t_list *new)
{
	t_list	*new_beg;

	new_beg = *alst;
	new -> next = new_beg;
	*alst = new_beg;
}
