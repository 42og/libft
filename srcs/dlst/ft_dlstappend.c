/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstappend.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/29 22:23:18 by mdeville          #+#    #+#             */
/*   Updated: 2018/03/01 13:27:23 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dlst.h"

void	ft_dlstappend(t_dlist **alst, t_dlist *new)
{
	if (!alst || !new)
		return ;
	new->prev = *alst;
	if (*alst)
	{
		new->next = (*alst)->next;
		if ((*alst)->next)
			(*alst)->next->prev = new;
		(*alst)->next = new;
	}
	else
		new->next = NULL;
	*alst = new;
}
