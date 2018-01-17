/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 15:24:32 by mdeville          #+#    #+#             */
/*   Updated: 2018/01/17 15:35:13 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERSION_H
# define CONVERSION_H

#include <stdint.h>

char				*ft_utoa_base(uintmax_t n, const char *base);
char				*ft_utoa(unsigned int n);
int					ft_atoi(const char *str);
intmax_t			ft_atoimax(const char *str);
char				*ft_itoa(int n);

#endif
