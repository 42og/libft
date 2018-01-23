/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstlink.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 19:09:20 by mdeville          #+#    #+#             */
/*   Updated: 2018/01/22 15:55:31 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "dlst.h"

t_dlist	*ft_dlstlink(void *content, size_t content_size)
{
	t_dlist *list;

	if (!(list = (t_dlist *)malloc(sizeof(t_dlist))))
		return (NULL);
	list->next = NULL;
	list->prev = NULL;
	list->content_size = (content) ? content_size : 0;
	list->content = content;
	return (list);
}
