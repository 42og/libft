/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_avlinsert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 17:59:12 by mdeville          #+#    #+#             */
/*   Updated: 2018/03/23 03:06:54 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "avltree.h"

static t_avltree	*insert(
							t_avltree *root,
							t_avltree *node,
							int (*f)(void *, void *))
{
	int balance;
	int cmp;

	if (!root)
		return (node);
	cmp = f(node->content, root->content);
	if (cmp < 0)
		root->left = insert(root->left, node, f);
	else if (cmp > 0)
		root->right = insert(root->right, node, f);
	else
		return (root);
	root->height = max(ft_avlheight(root->left), ft_avlheight(root->right)) + 1;
	balance = get_balance(root);
	cmp = (root->left) ? f(node->content, root->left->content) : 0;
	if (balance > 1 && cmp < 0)
		return (rotate_right(root));
	if (balance > 1 && cmp > 0)
		return (rotate_right_left(root));
	cmp = (root->right) ? f(node->content, root->right->content) : 0;
	if (balance < -1 && cmp > 0)
		return (rotate_left(root));
	if (balance < -1 && cmp < 0)
		return (rotate_left_right(root));
	return (root);
}

void				ft_avlinsert(
							t_avltree **root,
							t_avltree *node,
							int (*f)(void *, void *))
{
	if (!root || !node)
		return ;
	if (!*root)
	{
		*root = node;
		return ;
	}
	*root = insert(*root, node, f);
}
