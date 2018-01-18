/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/16 14:16:09 by mdeville          #+#    #+#             */
/*   Updated: 2018/01/17 16:25:24 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const unsigned char	*ptr1;
	unsigned char		*ptr2;

	ptr1 = src;
	ptr2 = dest;
	while (n)
	{
		*ptr2++ = *ptr1++;
		n--;
	}
	return (dest);
}
