/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstdel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 17:20:52 by mdeville          #+#    #+#             */
/*   Updated: 2018/01/24 21:54:39 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "dlst.h"

void	ft_dlstdel(t_dlist **alst, void (*del)(void *, size_t))
{
	t_dlist *tmp;

	if (!alst)
		return ;
	while (*alst)
	{
		tmp = (*alst)->next;
		if (del)
			(*del)((*alst)->content, (*alst)->content_size);
		free(*alst);
		*alst = tmp;
	}
}
