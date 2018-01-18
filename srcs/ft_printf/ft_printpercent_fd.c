/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printpercent_fd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 15:35:35 by mdeville          #+#    #+#             */
/*   Updated: 2018/01/17 22:00:01 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_printf.h"

int		ft_printpercent_fd(const int fd, t_token token)
{
	int cpt;

	cpt = 1;
	if (!ft_strchr(token.flags, '-'))
	{
		while (token.width-- > 1)
		{
			write(fd, " ", 1);
			cpt++;
		}
	}
	write(fd, "%", 1);
	while (token.width-- > 1)
	{
		write(fd, " ", 1);
		cpt++;
	}
	return (cpt);
}
