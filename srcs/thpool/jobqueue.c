/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jobqueue.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 15:02:21 by mdeville          #+#    #+#             */
/*   Updated: 2018/06/12 18:43:18 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "thpool.h"
#include <pthread.h>
#include <stdlib.h>

int		jobqueue_init(t_jobqueue *jobs)
{
	if (pthread_mutex_init(&jobs->job_mutex, NULL)
		|| pthread_mutex_init(&jobs->has_jobs.mutex, NULL)
		|| pthread_cond_init(&jobs->has_jobs.cond, NULL))
		return (0);
	jobs->has_jobs.v = 0;
	jobs->front = NULL;
	jobs->back = NULL;
	jobs->len = 0;
	return (1);
}

int		jobqueue_destroy(t_jobqueue *jobs)
{
	if (pthread_mutex_destroy(&jobs->has_jobs.mutex)
		|| pthread_cond_destroy(&jobs->has_jobs.cond))
		return (0);
	pthread_mutex_lock(&jobs->job_mutex);
	while (jobs->front)
	{
		free(jobs->front->content);
		free(jobs->front);
	}
	pthread_mutex_unlock(&jobs->job_mutex);
	if (pthread_mutex_destroy(&jobs->job_mutex))
		return (0);
	jobs->back = NULL;
	jobs->has_jobs.v = 0;
	jobs->len = 0;
	return (1);
}

int		thpool_add(t_thpool *pool, void (*f)(void *), void *args)
{
	t_job job;

	if (!f)
		return (0);
	job.func = f;
	job.arg = args;
	pthread_mutex_lock(&pool->jobs.job_mutex);
	ft_dlstprepend(&pool->jobs.front, ft_dlstnew(&job, sizeof(t_job)));
	if (!pool->jobs.back)
		pool->jobs.back = pool->jobs.front;
	pool->jobs.len += 1;
	bsem_post(&pool->jobs.has_jobs);
	pthread_mutex_unlock(&pool->jobs.job_mutex);
	return (1);
}
