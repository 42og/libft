/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_avldouble_rotate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 16:35:31 by mdeville          #+#    #+#             */
/*   Updated: 2018/03/22 17:51:30 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "avltree.h"

static inline void	balance_right_left(t_avltree *x, t_avltree *y, t_avltree *z)
{
	if (z->factor == AVL_RGT_HEAVY)
	{
		y->factor = AVL_BALANCED;
		x->factor = AVL_LFT_HEAVY;
	}
	else if (z->factor == AVL_BALANCED)
	{
		x->factor = AVL_BALANCED;
		y->factor = AVL_BALANCED;
	}
	else
	{
		y->factor = AVL_RGT_HEAVY;
		x->factor = AVL_BALANCED;
	}
}

t_avltree			*rotate_right_left(t_avltree *x)
{
	t_avltree	*y;
	t_avltree	*z;

	if (!x || !(y = x->right) || !(z = y->right))
		return (x);
	z->parent = x->parent;
	x->parent = z;
	y->parent = z;
	if (z->left)
		z->left->parent = x;
	if (z->right)
		z->right->parent = y;
	x->right = z->left;
	y->left = z->right;
	z->left = x;
	z->right = y;
	balance_right_left(x, y, z);
	return (z);
}

static inline void	balance_left_right(t_avltree *x, t_avltree *y, t_avltree *z)
{
	if (z->factor == AVL_RGT_HEAVY)
	{
		x->factor = AVL_BALANCED;
		y->factor = AVL_LFT_HEAVY;
	}
	else if (z->factor == AVL_BALANCED)
	{
		x->factor = AVL_BALANCED;
		y->factor = AVL_BALANCED;
	}
	else
	{
		y->factor = AVL_BALANCED;
		x->factor = AVL_RGT_HEAVY;
	}
}

t_avltree			*rotate_left_right(t_avltree *x)
{
	t_avltree *y;
	t_avltree *z;

	if (!x || !(y = x->left) || !(x = x->left))
		return (x);
	z->parent = x->parent;
	x->parent = z;
	y->parent = z;
	if (z->left)
		z->left->parent = y;
	if (z->right)
		z->right->parent = x;
	y->right = z->left;
	x->left = z->right;
	z->left = y;
	z->right = x;
	balance_left_right(x, y, z);
	return (z);
}
