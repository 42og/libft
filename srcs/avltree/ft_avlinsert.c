/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_avlinsert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 17:59:12 by mdeville          #+#    #+#             */
/*   Updated: 2018/03/22 16:34:36 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "avltree.h"

static void		bst_insert(
						t_avltree *root,
						t_avltree *node,
						int (*f)(void *, void *))
{
	if (f(root->content, node->content) >= 0)
	{
		if (root->left)
			bst_insert(root->left, node, f);
		else
		{
			node->parent = root;
			root->left = node;
		}
	}
	else
	{
		if (root->right)
			bst_insert(root->right, node, f);
		else
		{
			node->parent = root;
			root->right = node;
		}
	}
}

static t_avltree	*retrace(t_avltree *node)
{
	t_avltree *parent;

	parent = node->parent;
	while (parent)
	{
		
	}
}

void				ft_avlinsert(
						t_avltree **root,
						t_avltree *node,
						int (*f)(void *, void *))
{
	if (!root)
		return ;
	if (!*root)
	{
		*root = node;
		return ;
	}
	bst_insert(*root, node, f);
	*root = retrace(node);
}
