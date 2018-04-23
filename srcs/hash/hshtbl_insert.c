/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hshtbl_insert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 17:03:21 by mdeville          #+#    #+#             */
/*   Updated: 2018/04/11 16:44:09 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash.h"

void	hshtbl_insert(
					t_hshtbl *tbl,
					const void *data,
					size_t content_size)
{
	unsigned int	hash;
	t_list			*tmp;

	if (!tbl || !data || !tbl->buckets)
		return ;
	hash = tbl->hash(data) % tbl->buckets;
	if (hshtbl_lookup(tbl, data) || !(tmp = ft_lstnew(data, content_size)))
		return ;
	ft_lstadd(&tbl->table[hash], tmp);
	tbl->tblsize++;
}
