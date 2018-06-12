/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thpool.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 17:01:06 by mdeville          #+#    #+#             */
/*   Updated: 2018/06/12 17:58:39 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef THPOOL_H
# define THPOOL_H

# include <semaphore.h>
# include <pthread.h>
# include "dlst.h"

typedef struct		s_bsem
{
	pthread_mutex_t	mutex;
	pthread_cond_t	cond;
	int				v;
}					t_bsem;

typedef struct		s_job
{
	void			(*func)(void *);
	void			*arg;
}					t_job;

typedef struct		s_jobqueue
{
	pthread_mutex_t	job_mutex;
	t_bsem			has_jobs;
	t_dlist			*front;
	t_dlist			*back;
	size_t			len;
}					t_jobqueue;

typedef struct		s_thpool
{
	pthread_mutex_t	pool_mutex;
	pthread_cond_t	pool_cond;
	int				keep_alive;
	size_t			nb_th_alive;
	size_t			nb_th_working;
	t_jobqueue		jobs;
	pthread_t		*threads;
}					t_thpool;

t_thpool	*thpool_init(size_t nb_thread);
void		thpool_destroy(t_thpool *pool);

int		jobqueue_init(t_jobqueue *jobs);
int		jobqueue_destroy(t_jobqueue *jobs);
int		thpool_add(t_thpool *pool, void (*f)(void *), void *args);
void	bsem_post(t_bsem *bsem_p);
void	bsem_post_all(t_bsem *bsem_p);
void	bsem_wait(t_bsem *bsem_p);

#endif
