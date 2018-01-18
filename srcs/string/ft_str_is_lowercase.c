/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 22:07:36 by mdeville          #+#    #+#             */
/*   Updated: 2018/01/17 16:04:30 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ctype.h"
#include "ft_string.h"

int		ft_str_is_lowercase(const char *str)
{
	while (*str)
	{
		if (!ft_islower(*str++))
			return (0);
	}
	return (1);
}
