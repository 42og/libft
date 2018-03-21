/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_avlutils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 18:07:39 by mdeville          #+#    #+#             */
/*   Updated: 2018/03/21 18:58:14 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "avltree.h"

size_t	ft_avlsize(t_avltree *root)
{
	if (!root || (!root->left && !root->right))
		return (0);
	return (ft_avlsize(root->left) + ft_avlsize(root->right) + 1);
}

size_t	ft_avlheight(t_avltree *root)
{
	size_t	r_height;
	size_t	l_height;

	if (!root)
		return (0);
	else if (!root->left && !root->right)
		return (1);
	r_height = ft_avlheight(root->left);
	l_height = ft_avlheight(root->right);
	if (r_height > l_height)
		return (r_height + 1);
	return (l_height + 1);
}
