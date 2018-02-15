/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/30 13:15:25 by mdeville          #+#    #+#             */
/*   Updated: 2018/02/15 19:09:58 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dlst.h"

t_dlist	*ft_dlstmap(t_dlist *lst, t_dlist *(*f)(t_dlist *elem))
{
	t_dlist	*res;
	t_dlist	*prev;
	t_dlist	*curr;

	if (!lst || !f)
		return (NULL);
	res = (*f)(lst);
	if (!res)
		return (NULL);
	prev = res;
	lst = lst->next;
	while (lst)
	{
		curr = (*f)(lst);
		if (!curr)
			return (NULL);
		prev->next = curr;
		curr->prev = prev;
		prev = curr;
		lst = lst->next;
	}
	return (res);
}
