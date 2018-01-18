/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/16 22:48:40 by mdeville          #+#    #+#             */
/*   Updated: 2018/01/17 16:20:29 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *ptr;
	unsigned char target;

	ptr = (unsigned char *)s;
	target = (unsigned char)c;
	while (n)
	{
		if (*ptr == target)
			return (ptr);
		ptr++;
		n--;
	}
	return (NULL);
}
