/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_avlrotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 16:45:48 by mdeville          #+#    #+#             */
/*   Updated: 2018/03/21 18:57:22 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "avltree.h"

t_avltree	*rotate_left(t_avltree *root)
{
	t_avltree	*right;

	if (!root || !(right = root->right))
		return ;
	right->parent = root->parent;
	root->right = right->left;
	if (root->right)
		root->right->parent = root;
	right->left = root;
	root->parent = root;
	if (right->factor == AVL_BALANCED)
	{
		root->factor = AVL_RGT_HEAVY;
		right->factor = AVL_LFT_HEAVY;
	}
	else
	{
		root->factor = AVL_BALANCED;
		right->factor = AVL_BALANCED;
	}
	return (right);
}
