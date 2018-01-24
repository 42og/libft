/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_basename.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 16:32:22 by mdeville          #+#    #+#             */
/*   Updated: 2018/01/24 15:35:18 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*ft_basename(char *path)
{
	static char	dot[] = ".";
	char		*p;

	if (!path || !*path)
		return (dot);
	p = path + ft_strlen(path);
	while (p > path + 1 && *(p - 1) == '/')
		--p;
	*p = '\0';
	p = ft_strrchr(path, '/');
	return ((p) ? p + 1 : path);
}
