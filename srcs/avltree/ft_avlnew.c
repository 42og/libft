/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_avlnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 21:51:04 by mdeville          #+#    #+#             */
/*   Updated: 2018/03/23 01:10:14 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "memory.h"
#include "avltree.h"

t_avltree	*ft_avlnew(void const *content, size_t content_size)
{
	t_avltree *new_elem;

	new_elem = (t_avltree *)malloc(sizeof(t_avltree));
	if (!new_elem)
		return (NULL);
	new_elem->content = (content) ? malloc(content_size) : NULL;
	if (content && !new_elem->content)
	{
		free(new_elem);
		return (NULL);
	}
	if (content)
		ft_memcpy(new_elem->content, content, content_size);
	new_elem->content_size = (content) ? content_size : 0;
	new_elem->parent = NULL;
	new_elem->left = NULL;
	new_elem->right = NULL;
	new_elem->height = 1;
	return (new_elem);
}
