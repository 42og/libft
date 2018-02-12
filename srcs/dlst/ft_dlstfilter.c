/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstfilter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 16:08:29 by mdeville          #+#    #+#             */
/*   Updated: 2018/02/12 14:50:34 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dlst.h"

static inline void	ft_trimhead(
								t_dlist **alst,
								int (*p)(t_dlist *),
								void (*del)(void *, size_t))
{
	t_dlist *tmp;

	while (!(*p)(*alst))
	{
		tmp = *alst;
		*alst = (*alst)->next;
		ft_dlstdelone(&tmp, del);
	}
}

void				ft_dlstfilter(
								t_dlist **alst,
								int (*p)(t_dlist *),
								void (*del)(void *, size_t))
{
	t_dlist *tmp;
	t_dlist *curr;

	if (!alst)
		return ;
	ft_trimhead(alst, p, del);
	curr = (*alst) ? (*alst)->next : NULL;
	while (curr)
	{
		if (!(*p)(curr))
		{
			tmp = curr->next;
			ft_dlstdelone(&curr, del);
			curr = tmp;
		}
		else
			curr = curr->next;
	}
}
