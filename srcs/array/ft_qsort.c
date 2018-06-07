/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qsort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 01:14:41 by mdeville          #+#    #+#             */
/*   Updated: 2018/06/07 15:52:28 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "memory.h"

static inline void	*tab_at(void *tab, size_t nmemb, size_t index)
{
	return (tab + (nmemb * index));
}

static int			partition(
							void *base,
							size_t nmemb,
							size_t size,
							int (*compar)(const void *, const void *))
{
	size_t	i;
	size_t	j;
	void	*t_i;
	void	*t_j;
	void	*t_last;

	t_last = tab_at(base, nmemb, size - 1);
	ft_memswap(base, t_last, nmemb);
	j = 0;
	i = 0;
	while (i < size - 1)
	{
		t_i = tab_at(base, nmemb, i);
		if (compar(t_i, t_last) <= 0)
		{
			t_j = tab_at(base, nmemb, j);
			ft_memswap(t_i, t_j, nmemb);
			j += 1;
		}
		i += 1;
	}
	ft_memswap(t_last, tab_at(base, nmemb, j), nmemb);
	return (j);
}

void				ft_qsort(
							void *base,
							size_t nmemb,
							size_t size,
							int (*compar)(const void *, const void *))
{
	char	*tmp;
	size_t	pivot;

	if (size <= 1 || !base || !nmemb || !compar)
		return ;
	if (size == 2)
	{
		tmp = (char *)base + nmemb;
		if (compar(base, tmp) > 0)
			ft_memswap(base, tmp, nmemb);
		return ;
	}
	pivot = partition(base, nmemb, size, compar);
	ft_qsort(base, nmemb, pivot, compar);
	tmp = (char *)base + nmemb * (pivot + 1);
	ft_qsort(tmp, nmemb, size - pivot - 1, compar);
}
