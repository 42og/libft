/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 18:27:57 by mdeville          #+#    #+#             */
/*   Updated: 2018/01/17 16:22:23 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/lst.h"
#include <stdlib.h>

void	*ft_lstpop(t_list **alst, size_t *content_size)
{
	void	*res;
	t_list	*next;

	if (!alst || !*alst)
		return (NULL);
	res = (*alst)->content;
	if (content_size)
		*content_size = (*alst)->content_size;
	next = (*alst)->next;
	free(*alst);
	*alst = next;
	return (res);
}
