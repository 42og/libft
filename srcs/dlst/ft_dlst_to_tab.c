/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 20:02:04 by mdeville          #+#    #+#             */
/*   Updated: 2018/01/22 20:47:01 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "memory.h"
#include "dlst.h"

void	**ft_dlst_to_tab(t_dlist *list)
{
	size_t	i;
	size_t	len;
	void	**res;

	len = ft_dlstlen(list);
	if (!(res = (void **)malloc(sizeof(void *) * (len + 1))))
		return (NULL);
	i = 0;
	while (list)
	{
		res[i] = list->content;
		list = list->next;
		i += 1;
	}
	res[i] = NULL;
	return (res);
}
