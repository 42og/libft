/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstdelone.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/29 19:01:57 by mdeville          #+#    #+#             */
/*   Updated: 2018/02/12 14:47:23 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "dlst.h"

void	ft_dlstdelone(t_dlist **alst, void (*del)(void *, size_t))
{
	t_dlist	*tmp;

	if (!alst || !*alst || !del)
		return ;
	tmp = *alst;
	*alst = (!tmp->next && tmp->prev) ? tmp->prev : tmp->next;
	if (del)
		(*del)(tmp->content, tmp->content_size);
	if (tmp->prev)
		tmp->prev->next = tmp->next;
	if (tmp->next)
		tmp->next->prev = tmp->prev;
	free(tmp);
}
