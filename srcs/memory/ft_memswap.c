/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memswap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 02:15:57 by mdeville          #+#    #+#             */
/*   Updated: 2018/06/07 02:18:56 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	ft_memswap(void *s1, void *s2, size_t n)
{
	char tmp;
	char *p1;
	char *p2;

	p1 = (char *)s1;
	p2 = (char *)s2;
	while (n)
	{
		tmp = *p1;
		*p1 = *p2;
		*p2 = tmp;
		p1 += 1;
		p2 += 1;
		n -= 1;
	}
}
