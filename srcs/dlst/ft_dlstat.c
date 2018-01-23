/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 16:48:47 by mdeville          #+#    #+#             */
/*   Updated: 2018/01/22 16:50:04 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dlst.h"

t_dlist	*ft_dlstat(t_dlist *head, size_t index)
{
	size_t i;

	i = 0;
	while (head && i < index)
	{
		head = head->next;
		i++;
	}
	return (head);
}
