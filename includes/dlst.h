/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlst.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 15:15:45 by mdeville          #+#    #+#             */
/*   Updated: 2018/01/18 10:45:28 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DLST_H
# define DLST_H

# include <unistd.h>

typedef struct		s_dlist
{
	void			*content;
	size_t			content_size;
	struct s_dlist	*next;
	struct s_dlist	*prev;
}					t_dlist;

void				ft_dlstappend(t_dlist **alst, t_dlist *new);

void				ft_dlstdel(t_dlist **alst, void (*del)(void *, size_t));

void				ft_dlstdel_back(
									t_dlist **alst,
									void (*del)(void *, size_t));

void				ft_dlstdel_front(
									t_dlist **alst,
									void (*del)(void *, size_t));

void				ft_dlstdelone(t_dlist **alst, void (*del)(void *, size_t));

void				ft_dlstfilter(
								t_dlist **alst,
								int (*p)(t_dlist *),
								void (*del)(void *, size_t));

t_dlist				*ft_dlstnew(char const *content, size_t content_size);

void				ft_dlstprepend(t_dlist **alst, t_dlist *new);

void				ft_dlstreverse(t_dlist **alst);

#endif
