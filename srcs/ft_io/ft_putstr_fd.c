/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 16:15:04 by mdeville          #+#    #+#             */
/*   Updated: 2018/01/17 16:23:26 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_io.h"
#include "ft_string.h"

void	ft_putstr_fd(char const *s, int fd)
{
	size_t len;

	if (!s)
		return ;
	len = ft_strlen(s);
	write(fd, s, len);
}
