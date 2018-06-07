/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 15:00:31 by mdeville          #+#    #+#             */
/*   Updated: 2018/06/07 11:43:34 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASH_H
# define HASH_H

# include <unistd.h>
# include "lst.h"

typedef struct		s_hshtbl {
	t_list			**table;
	size_t			buckets;
	size_t			tblsize;
	unsigned int	(*hash)(const void *);
	void			(*destroy)(void *);
	int				(*cmp)(const void *, const void *);
}					t_hshtbl;

t_hshtbl			*hshtbl_init(
								size_t buckets,
								unsigned int (*hash)(const void *),
								void (*destroy)(void *),
								int (*cmp)(const void *, const void *));

void				hshtbl_insert(
								t_hshtbl *tbl,
								const void *data,
								size_t content_size);

void				*hshtbl_lookup(
								t_hshtbl *tbl,
								const void *data);

void				*hshtbl_remove(
								t_hshtbl *tbl,
								void *data);

size_t				hshtbl_size(t_hshtbl *tbl);

#endif
