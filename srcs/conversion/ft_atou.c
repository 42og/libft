/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atou.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 12:12:29 by mdeville          #+#    #+#             */
/*   Updated: 2018/01/18 15:49:59 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_atou(const char *str)
{
	unsigned int res;

	while ((*str > 8 && *str < 14) || *str == ' ')
		str++;
	if (*str == '+')
		str++;
	res = 0;
	while (*str >= '0' && *str <= '9')
		res = res * 10 + (*str++ - '0');
	return (res);
}
