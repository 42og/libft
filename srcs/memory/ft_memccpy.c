/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/16 14:34:29 by mdeville          #+#    #+#             */
/*   Updated: 2018/01/17 16:20:13 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char		*ptr1;
	const unsigned char	*ptr2;

	ptr1 = dest;
	ptr2 = src;
	while (n)
	{
		*ptr1 = *ptr2;
		if (*ptr2 == (unsigned char)c)
			return (ptr1 + 1);
		ptr1++;
		ptr2++;
		n--;
	}
	return (NULL);
}
