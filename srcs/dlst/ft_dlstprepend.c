/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstprepend.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/29 22:23:18 by mdeville          #+#    #+#             */
/*   Updated: 2018/01/17 15:54:27 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dlst.h"

void	ft_dlstprepend(t_dlist **alst, t_dlist *new)
{
	if (!alst || !new)
		return ;
	new->next = *alst;
	if (*alst)
		new->prev = (*alst)->prev;
	else
		new->prev = NULL;
	*alst = new;
}
