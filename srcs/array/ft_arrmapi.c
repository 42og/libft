/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 16:12:39 by mdeville          #+#    #+#             */
/*   Updated: 2018/06/07 16:13:51 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include "memory.h"

void	*ft_arrmap(
				void *base,
				size_t nmemb,
				size_t size,
				void *(*f)(void *, size_t))
{
	char	*p;
	char	*p2;
	void	*res;
	size_t	i;

	if (!base || !size || !nmemb || !f || !(res = malloc(nmemb * size)))
		return (NULL);
	p2 = (char *)res;
	p = (char *)base;
	i = 0;
	while (size)
	{
		ft_memcpy(p2, f(p, i), nmemb);
		p += nmemb;
		p2 += nmemb;
		size -= 1;
		i += 1;
	}
	return (res);
}
