/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_avlremove.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 02:43:27 by mdeville          #+#    #+#             */
/*   Updated: 2018/03/23 03:46:44 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "avltree.h"

static t_avltree	*remove(
							t_avltree **res,
							t_avltree *root,
							void *dataref,
							int (*f)(void *, void *))
{
	int			cmp;
	t_avltree	*tmp;

	if (!root)
		return (root);
	cmp = (*f)(dataref, root->content);
	if (cmp < 0)
		root->left = remove(res, root->left, dataref, f);
	else if (cmp > 0)
		root->right = remove(res, root->right, dataref, f);
	else if (!root->left || !root->right)
	{
		ft_bzero(&root->parent, 3 * sizeof(t_avltree *));
		*res = root;
		tmp = (root->left) ? root->left : root->right;
		if (!tmp)
			return (NULL);
		else
			*root = *tmp;
	}
	else
	{
		
	}
}

t_avltree			*ft_avlremove(
							t_avltree **root,
							void *dataref,
							int (*f)(void *, void *))
{
	t_avltree *res;

	if (!root || !dataref)
		return (NULL);
	if (!*root)
	{
		res = *root;
		*root = NULL;
		return (res);
	}
	res = NULL;
	*root = remove(&res, *root, dataref, f);
	return (res);
}
