/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 15:57:28 by mdeville          #+#    #+#             */
/*   Updated: 2018/01/17 16:23:04 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_io.h"
#include "ft_string.h"

void	ft_putstr(char const *s)
{
	size_t len;

	if (!s)
		return ;
	len = ft_strlen(s);
	write(1, s, len);
}
