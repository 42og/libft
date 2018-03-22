/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avltree.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 15:19:28 by mdeville          #+#    #+#             */
/*   Updated: 2018/03/22 21:32:23 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AVLTREE_H
# define AVLTREE_H

# include <unistd.h>
# define AVL_LFT_HEAVY -1
# define AVL_RGT_HEAVY 1
# define AVL_BALANCED 0

typedef struct			s_avltree
{
	void				*content;
	size_t				content_size;
	int					factor;
	struct s_avltree	*left;
	struct s_avltree	*right;
	struct s_avltree	*parent;
}						t_avltree;

/*
** Utilities
*/

size_t					ft_avlsize(t_avltree *root);
size_t					ft_avlheight(t_avltree *root);

/*
** Rotate
*/

t_avltree				*rotate_left(t_avltree *root);
t_avltree				*rotate_right(t_avltree *root);
t_avltree				*rotate_left_right(t_avltree *root);
t_avltree				*rotate_right_left(t_avltree *root);

void					ft_avlinsert(
								t_avltree **root,
								t_avltree *node,
								int (*f)(void *, void *));
t_avltree				*ft_avlnew(void const *content, size_t content_size);

#endif
