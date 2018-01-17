/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 20:24:11 by mdeville          #+#    #+#             */
/*   Updated: 2017/11/27 16:01:02 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# define BUFF_SIZE 32

typedef struct		s_clist
{
	int				fd;
	int				offset;
	char			buff[BUFF_SIZE + 1];
	struct s_clist	*next;
}					t_clist;

int					get_next_line(const int fd, char **line);

#endif
