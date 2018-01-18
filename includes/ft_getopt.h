/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getopt.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 16:04:46 by mdeville          #+#    #+#             */
/*   Updated: 2018/01/17 16:29:24 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GETOPT_H
# define FT_GETOPT_H

extern char	*g_optarg;
extern int	g_optind;
extern int	g_opterr;
extern int	g_optopt;

int			ft_getopt(int argc, char *const argv[], const char *opstring);

#endif
