/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_avlrotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 16:45:48 by mdeville          #+#    #+#             */
/*   Updated: 2018/06/07 11:43:09 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "avltree.h"

t_avltree	*rotate_left(t_avltree *x)
{
	t_avltree	*z;

	if (!x || !(z = x->right))
		return (x);
	z->parent = x->parent;
	x->right = z->left;
	if (x->right)
		x->right->parent = x;
	z->left = x;
	x->parent = z;
	x->height = max(ft_avlheight(x->left), ft_avlheight(x->right)) + 1;
	z->height = max(ft_avlheight(z->left), ft_avlheight(z->right)) + 1;
	return (z);
}

t_avltree	*rotate_right(t_avltree *x)
{
	t_avltree	*z;

	if (!x || !(z = x->left))
		return (x);
	z->parent = x->parent;
	x->left = z->right;
	if (x->left)
		x->left->parent = x;
	z->right = x;
	x->parent = z;
	x->height = max(ft_avlheight(x->left), ft_avlheight(x->right));
	z->height = max(ft_avlheight(z->left), ft_avlheight(z->right));
	return (z);
}

t_avltree	*rotate_right_left(t_avltree *x)
{
	x->right = rotate_right(x->right);
	return (rotate_left(x));
}

t_avltree	*rotate_left_right(t_avltree *x)
{
	x->left = rotate_right(x->left);
	return (rotate_right(x));
}
