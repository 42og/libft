/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 15:15:27 by mdeville          #+#    #+#             */
/*   Updated: 2018/06/07 15:50:14 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include "memory.h"

void	*ft_arrmap(void *base, size_t nmemb, size_t size, void *(*f)(void *))
{
	char *p;
	char *p2;
	void *res;

	if (!base || !size || !nmemb || !f || !(res = malloc(nmemb * size)))
		return (NULL);
	p2 = (char *)res;
	p = (char *)base;
	while (size)
	{
		ft_memcpy(p2, f(p), nmemb);
		p += nmemb;
		p2 += nmemb;
		size -= 1;
	}
	return (res);
}
