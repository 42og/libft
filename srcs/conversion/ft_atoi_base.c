/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 18:13:34 by mdeville          #+#    #+#             */
/*   Updated: 2018/06/08 13:26:22 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "ft_string.h"

int	ft_atoi_base(
				const char *str,
				const char *base,
				const char *whitespace,
				char minus)
{
	int		res;
	int		neg;
	size_t	len;
	char	*index;

	res = 0;
	neg = 1;
	len = ft_strlen(base);
	while (*str && ft_strchr(whitespace, *str))
		str++;
	neg = (*str == minus) ? -1 : 1;
	str = (neg == -1) ? str + 1 : str;
	while (*str && (index = ft_strchr(base, *str)))
	{
		res = res * (int)len + (index - base);
		++str;
	}
	return (res * neg);
}
