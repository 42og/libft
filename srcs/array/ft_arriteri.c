/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arriteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 16:11:01 by mdeville          #+#    #+#             */
/*   Updated: 2018/06/07 16:14:07 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	ft_arriter(
					void *array,
					size_t nmemb,
					size_t size,
					void (*f)(void *, size_t))
{
	char	*p;
	size_t	i;

	if (!array || !size || !nmemb || !f)
		return ;
	p = (char *)array;
	i = 0;
	while (size)
	{
		f(p, i);
		p += nmemb;
		size -= 1;
		i += 1;
	}
}
