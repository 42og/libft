/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_avlinsert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 17:59:12 by mdeville          #+#    #+#             */
/*   Updated: 2018/03/22 21:26:20 by mdeville         ###   ########.fr       */
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

static void		retrace(t_avltree **root, t_avltree *node)
{
	t_avltree	*parent;
	t_avltree	*grand_parent;
	t_avltree	*after_rotate;

	parent = node->parent;
	while (parent)
	{
		if (parent->right == node)
		{
			if (parent->factor == AVL_RGT_HEAVY)
			{
				grand_parent = parent->parent;
				after_rotate = (node->factor == AVL_LFT_HEAVY) ?
					rotate_right_left(parent) :
					rotate_right(parent);
			}
			else
			{
				if (parent->factor == AVL_LFT_HEAVY)
				{
					parent->factor = 0;
					return ;
				}
				parent->factor = AVL_RGT_HEAVY;
				node = parent;
				continue ;
			}
		}
		else if (parent->factor == AVL_LFT_HEAVY)
		{
			grand_parent = parent->parent;
			after_rotate = (node->factor == AVL_RGT_HEAVY) ?
					rotate_left_right(parent) :
					rotate_left(parent);
		}
		else
		{
			if (parent->factor == AVL_RGT_HEAVY)
			{
				parent->factor = 0;
				return ;
			}
			parent->factor = AVL_RGT_HEAVY;
			node = parent;
			continue ;
		}
		after_rotate->parent = grand_parent;
		if (!grand_parent)
		{
			if (parent == grand_parent->left)
				grand_parent->left = after_rotate;
			else
				grand_parent->right = after_rotate;
		}
		else
		{
			*root = after_rotate;
			return ;
		}
		parent = parent->parent;
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
	retrace(root, node);
}
