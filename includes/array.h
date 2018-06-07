/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 01:27:17 by mdeville          #+#    #+#             */
/*   Updated: 2018/06/07 11:45:07 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_H
# define ARRAY_H

# include "dlst.h"

t_dlist		*ft_tab_to_dlst(void *tab, size_t nmemb, size_t size);
void		ft_qsort(
					void *base,
					size_t nmemb,
					size_t size,
					int (*compar)(const void *, const void *));

#endif
