/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstappend.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/29 22:23:18 by mdeville          #+#    #+#             */
/*   Updated: 2018/05/24 23:44:04 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dlst.h"

void	ft_dlstappend(t_dlist **alst, t_dlist *new)
{
	t_dlist *walk;

	if (!alst)
		return ;
	if (!*alst)
		*alst = new;
	else
	{
		walk = *alst;
		while (walk->next)
			walk = walk->next;
		walk->next = new;
		new->prev = walk;
	}
}
