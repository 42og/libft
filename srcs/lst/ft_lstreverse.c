/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstreverse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 10:57:02 by mdeville          #+#    #+#             */
/*   Updated: 2018/01/17 15:51:31 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"

void	ft_lstreverse(t_list **alst)
{
	t_list *prev;
	t_list *curr;
	t_list *tmp;

	if (!alst || !*alst)
		return ;
	curr = *alst;
	prev = NULL;
	while (curr)
	{
		tmp = curr->next;
		curr->next = prev;
		prev = curr;
		curr = tmp;
	}
	*alst = prev;
}
