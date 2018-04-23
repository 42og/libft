/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hshtbl_lookup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 18:28:39 by mdeville          #+#    #+#             */
/*   Updated: 2018/04/11 16:44:53 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash.h"

void	*hshtbl_lookup(t_hshtbl *tbl, const void *data)
{
	t_list	*walk;

	if (!tbl || !data || !tbl->buckets)
		return (NULL);
	walk = tbl->table[tbl->hash(data) % tbl->buckets];
	while (walk)
	{
		if (tbl->cmp(walk->content, data))
			return (walk->content);
		walk = walk->next;
	}
	return (NULL);
}
