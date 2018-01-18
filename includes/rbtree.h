/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbtree.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 15:19:28 by mdeville          #+#    #+#             */
/*   Updated: 2018/01/18 10:44:43 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBTREE_H
# define RBTREE_H

# include <unistd.h>

enum				e_color {RED, BLACK, NONE};

typedef struct		s_rbnode
{
	enum e_color	color;
	void			*content;
	size_t			content_size;
	struct s_rbnode	*left;
	struct s_rbnode	*right;
}					t_rbnode;

t_rbnode			*ft_rbnodenew(void const *content, size_t content_size);

#endif
