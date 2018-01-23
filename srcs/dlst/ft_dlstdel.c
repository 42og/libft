/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstdel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 17:20:52 by mdeville          #+#    #+#             */
/*   Updated: 2018/01/23 15:36:55 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dlst.h"

void	ft_dlstdel(t_dlist **alst, void (*del)(void *, size_t))
{
	t_dlist **tmp;

	if (!alst || !*alst)
		return ;
	tmp = &((*alst)->next);
	ft_dlstdel_front(tmp, del);
	ft_dlstdel_back(alst, del);
}
