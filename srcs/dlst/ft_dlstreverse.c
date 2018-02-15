/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstreverse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 15:48:20 by mdeville          #+#    #+#             */
/*   Updated: 2018/02/15 19:23:22 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dlst.h"

void	ft_dlstreverse(t_dlist **alst)
{
	t_dlist *prev;
	t_dlist *curr;
	t_dlist *tmp;

	if (!alst)
		return ;
	curr = *alst;
	prev = NULL;
	while (curr)
	{
		tmp = curr->next;
		curr->next = prev;
		curr->prev = tmp;
		prev = curr;
		curr = tmp;
	}
	*alst = prev;
}
