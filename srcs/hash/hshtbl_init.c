/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hshtbl_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 16:23:57 by mdeville          #+#    #+#             */
/*   Updated: 2018/06/07 11:42:10 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "memory.h"
#include "hash.h"

t_hshtbl		*hshtbl_init(
							size_t buckets,
							unsigned int (*hash)(const void *),
							void (*destroy)(void *),
							int (*cmp)(const void *, const void *))
{
	t_hshtbl *newtbl;

	if (!(newtbl = (t_hshtbl *)malloc(sizeof(t_hshtbl))))
		return (NULL);
	newtbl->destroy = destroy;
	newtbl->cmp = cmp;
	newtbl->hash = hash;
	newtbl->buckets = buckets;
	if (!(newtbl->table = (t_list **)malloc(sizeof(t_list *) * buckets)))
	{
		free(newtbl);
		return (NULL);
	}
	ft_bzero(newtbl->table, sizeof(t_list *) * buckets);
	return (newtbl);
}
