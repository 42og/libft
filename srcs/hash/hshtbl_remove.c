/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hshtbl_remove.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 18:35:18 by mdeville          #+#    #+#             */
/*   Updated: 2018/04/11 16:45:11 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "hash.h"

void	*hshtbl_remove(t_hshtbl *tbl, void *data)
{
	t_list	*tmp;
	void	*res;

	if (!tbl || !data || !tbl->buckets)
		return (NULL);
	tmp = ft_lstremove(
					&tbl->table[tbl->hash(data) % tbl->buckets],
					data,
					tbl->cmp);
	if (!tmp)
		return (NULL);
	res = tmp->content;
	free(tmp);
	return (res);
}
