/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 22:07:36 by mdeville          #+#    #+#             */
/*   Updated: 2018/01/17 16:06:04 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ctype.h"
#include "ft_string.h"

int		ft_str_is_uppercase(const char *str)
{
	while (*str)
	{
		if (!ft_isupper(*str++))
			return (0);
	}
	return (1);
}
