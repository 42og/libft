/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstremove.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 18:14:12 by mdeville          #+#    #+#             */
/*   Updated: 2018/01/19 18:24:52 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"

t_list	*ft_lstremove(
				t_list **list,
				void *dataref,
				int (*cmp)(const void *, const void *))
{
	t_list *tmp;
	t_list *prev;

	if (!list || !cmp || !dataref)
		return (NULL);
	prev = NULL;
	tmp = *list;
	while (tmp)
	{
		if (!cmp(tmp->content, dataref))
		{
			if (prev)
				prev->next = tmp->next;
			else
				*list = tmp->next;
			tmp->next = NULL;
			return (tmp);
		}
		prev = tmp;
		tmp = tmp->next;
	}
	return (NULL);
}
