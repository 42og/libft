/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thpool.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 17:01:06 by mdeville          #+#    #+#             */
/*   Updated: 2018/06/11 18:05:20 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef THPOOL_H
# define THPOOL_H

# include <pthread.h>
# include "dlst.h"

typedef struct	s_jobqueue
{
	pthread_mutex_t	job_mutex;
	t_dlist			*front;
	t_dlist			*back;
	size_t			len;
}				t_jobqueue;

typedef struct	s_thpool
{
	pthread_mutex_t	pool_mutex;
	int				nb_th_alive;
	int				nb_th_working;
	t_jobqueue		jobs;
	pthread_t		*threads;
}				t_thpool;

t_thpool	*thpool_init(size_t nb_thread);

#endif
