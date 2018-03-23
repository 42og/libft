/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_avldel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 02:46:22 by mdeville          #+#    #+#             */
/*   Updated: 2018/03/23 02:53:16 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "avltree.h"

static void		recursive(t_avltree *node, void (*f)(void *, size_t))
{
	t_avltree *left;
	t_avltree *right;

	if (!node)
		return ;
	left = node->left;
	right = node->right;
	if (f)
		(*f)(node->content, node->content_size);
	free(node);
	recursive(left, f);
	recursive(right, f);
}

void			ft_avldel(t_avltree **root, void (*f)(void *, size_t))
{
	if (!root)
		return ;
	recursive(*root, f);
}
