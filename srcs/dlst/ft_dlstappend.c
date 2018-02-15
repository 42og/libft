/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstappend.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/29 22:23:18 by mdeville          #+#    #+#             */
/*   Updated: 2018/02/15 20:51:47 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dlst.h"

void	ft_dlstappend(t_dlist **alst, t_dlist *new)
{
	t_dlist	*curr;

	if (!alst || !new)
		return ;
	new->next = NULL;
	if (!*alst)
	{
		new->prev = NULL;
		*alst = new;
	}
	else
	{
		curr = *alst;
		while (curr->next)
			curr = curr->next;
		curr->next = new;
		new->prev = curr;
	}
}
