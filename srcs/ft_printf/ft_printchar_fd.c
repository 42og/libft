/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printchar_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 16:13:15 by mdeville          #+#    #+#             */
/*   Updated: 2018/01/17 21:56:00 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_printf.h"

int		ft_printchar_fd(const int fd, t_token token, va_list *ap)
{
	int		width;
	char	c;
	int		cpt;

	width = token.width;
	c = va_arg(*ap, int);
	cpt = 1;
	if (!ft_strchr(token.flags, '-'))
	{
		while (width > 1)
		{
			write(fd, " ", 1);
			width--;
			cpt++;
		}
	}
	write(fd, &c, 1);
	while (width > 1)
	{
		write(fd, " ", 1);
		width--;
		cpt++;
	}
	return (cpt);
}
