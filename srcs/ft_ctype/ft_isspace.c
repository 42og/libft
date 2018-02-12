/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 13:14:46 by mdeville          #+#    #+#             */
/*   Updated: 2017/11/12 21:46:17 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_isspace(int c)
{
	return (c == ' '
			|| c == '\t'
			|| c == '\n'
			|| c == '\f'
			|| c == '\v'
			|| c == '\r');
}