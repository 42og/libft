/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstremove.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 18:14:12 by mdeville          #+#    #+#             */
/*   Updated: 2018/01/22 15:58:37 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dlst.h"

t_dlist	*ft_dlstremove(
				t_dlist **list,
				void *dataref,
				int (*cmp)(const void *, const void *))
{
	t_dlist *tmp;

	if (!list || !cmp || !dataref)
		return (NULL);
	tmp = *list;
	while (tmp)
	{
		if (!cmp(tmp->content, dataref))
		{
			if (tmp->prev)
				tmp->prev->next = tmp->next;
			else
				*list = tmp->next;
			tmp->next = NULL;
			return (tmp);
		}
		tmp = tmp->next;
	}
	return (NULL);
}
