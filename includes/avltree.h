/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avltree.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 15:19:28 by mdeville          #+#    #+#             */
/*   Updated: 2018/03/23 00:40:28 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AVLTREE_H
# define AVLTREE_H

# include <unistd.h>

typedef struct			s_avltree
{
	void				*content;
	size_t				content_size;
	int					height;
	struct s_avltree	*left;
	struct s_avltree	*right;
	struct s_avltree	*parent;
}						t_avltree;

/*
** Utilities
*/

int						max(int a, int b);
int						get_balance(t_avltree *node);
int						ft_avlmax(t_avltree *node);
int						ft_avlsize(t_avltree *root);
int						ft_avlheight(t_avltree *node);

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
