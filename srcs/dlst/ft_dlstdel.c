/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstdel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 17:20:52 by mdeville          #+#    #+#             */
/*   Updated: 2018/01/17 15:53:01 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dlst.h"

void	ft_dlstdel(t_dlist **alst, void (*del)(void *, size_t))
{
	t_dlist **tmp;

	if (!alst || !*alst || !del)
		return ;
	tmp = &((*alst)->next);
	ft_dlstdel_front(tmp, del);
	ft_dlstdel_back(alst, del);
}
