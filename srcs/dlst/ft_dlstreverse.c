/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstreverse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 15:48:20 by mdeville          #+#    #+#             */
/*   Updated: 2018/01/17 15:54:39 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dlst.h"

void	ft_dlstreverse(t_dlist **alst)
{
	t_dlist *tmp;

	if (!alst)
		return ;
	while (*alst)
	{
		tmp = (*alst)->next;
		(*alst)->next = (*alst)->prev;
		(*alst)->prev = tmp;
		*alst = tmp;
	}
}
