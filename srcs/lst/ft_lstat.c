/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 15:09:31 by mdeville          #+#    #+#             */
/*   Updated: 2018/01/22 15:12:13 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"

t_list	*ft_lstat(t_list *head, size_t index)
{
	size_t i;

	if (!head)
		return (NULL);
	i = 0;
	while (head && i < index)
	{
		head = head->next;
		i += 1;
	}
	return (head);
}
