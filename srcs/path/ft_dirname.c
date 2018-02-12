/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dirname.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 14:53:59 by mdeville          #+#    #+#             */
/*   Updated: 2018/01/27 21:23:36 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*dirname(char *path)
{
	static char	dot[] = ".";
	char		*p;

	if (!path || !*path || !(p = ft_strchr(path, '/')))
		return (dot);
	p = path + ft_strlen(path);
	while (p > path && *(p - 1) == '/')
		--p;
	while (p > path && *(p - 1) != '/')
		--p;
	while (p > path && *(p - 1) == '/')
		--p;
	*p = '\0';
	return (path);
}
