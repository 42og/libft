/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstprepend.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/29 22:23:18 by mdeville          #+#    #+#             */
/*   Updated: 2018/02/15 20:38:30 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dlst.h"

void	ft_dlstprepend(t_dlist **alst, t_dlist *new)
{
	if (!alst || !new)
		return ;
	new->next = *alst;
	if (*alst)
	{
		new->prev = (*alst)->prev;
		if ((*alst)->prev)
			(*alst)->prev->next = new;
		(*alst)->prev = new;
	}
	else
		new->prev = NULL;
	*alst = new;
}
