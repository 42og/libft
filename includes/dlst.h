/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlst.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 15:15:45 by mdeville          #+#    #+#             */
/*   Updated: 2018/06/07 01:58:08 by mdeville         ###   ########.fr       */
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
t_dlist				*ft_dlstat(t_dlist *head, size_t index);
t_dlist				*ft_dlstcpy(t_dlist *head);
void				ft_dlstdel(t_dlist **alst, void (*del)(void *, size_t));
void				ft_dlstdelone(t_dlist **alst, void (*del)(void *, size_t));
void				ft_dlstiter(t_dlist *lst, void (*f)(t_dlist *elem));
t_dlist				*ft_dlstlink(void *content, size_t content_size);
void				ft_dlstfilter(
								t_dlist **alst,
								int (*p)(t_dlist *),
								void (*del)(void *, size_t));
t_dlist				*ft_dlstnew(void const *content, size_t content_size);
void				ft_dlstprepend(t_dlist **alst, t_dlist *new);
void				ft_dlstreverse(t_dlist **alst);
t_dlist				*ft_dlstremove(
								t_dlist **head,
								void *data,
								int (*cmp)(const void *, const void *));
t_dlist				*ft_dlstpop(t_dlist **alst);
size_t				ft_dlstlen(t_dlist *list);
void				*ft_dlst_to_tab(t_dlist *lst);
void				ft_dlstsort(t_dlist **head,
								int (*cmp)(t_dlist *l1, t_dlist *l2));

#endif
