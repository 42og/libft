/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstappend.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/29 22:23:18 by mdeville          #+#    #+#             */
/*   Updated: 2018/01/17 15:52:38 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/dlst.h"

void	ft_dlstappend(t_dlist **alst, t_dlist *new)
{
	if (!alst || !new)
		return ;
	new->prev = *alst;
	if (*alst)
		new->next = (*alst)->next;
	else
		new->next = NULL;
	*alst = new;
}
