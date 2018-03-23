/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_avlutils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 18:07:39 by mdeville          #+#    #+#             */
/*   Updated: 2018/03/23 00:40:34 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "avltree.h"

int		max(int a, int b)
{
	return ((a >= b) ? a : b);
}

int		ft_avlsize(t_avltree *root)
{
	if (!root || (!root->left && !root->right))
		return (0);
	return (ft_avlsize(root->left) + ft_avlsize(root->right) + 1);
}

int		ft_avlheight(t_avltree *node)
{
	if (!node)
		return (0);
	return (node->height);
}

int		get_balance(t_avltree *node)
{
	if (!node)
		return (0);
	return (ft_avlheight(node->left) - ft_avlheight(node->right));
}
