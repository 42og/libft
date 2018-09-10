/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thpool_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 18:04:13 by mdeville          #+#    #+#             */
/*   Updated: 2018/09/10 14:58:15 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <semaphore.h>
#include <pthread.h>
#include <stdlib.h>
#include "dlst.h"
#include "thpool.h"

static void	exec_job(t_jobqueue *jobs)
{
	t_dlist	*elem;
	t_job	*job;

	elem = NULL;
	pthread_mutex_lock(&jobs->job_mutex);
	if (jobs->len == 1)
	{
		jobs->front = NULL;
		elem = ft_dlstpop(&jobs->back);
		jobs->len = 0;
	}
	else
	{
		elem = ft_dlstpop(&jobs->back);
		jobs->len -= 1;
		bsem_post(&jobs->has_jobs);
	}
	pthread_mutex_unlock(&jobs->job_mutex);
	if (!elem)
		return ;
	job = (t_job *)elem->content;
	job->func(job->arg);
	free(job);
}

static void	*thread_do(t_thpool *pool)
{
	pthread_mutex_lock(&pool->pool_mutex);
	pool->nb_th_alive += 1;
	pthread_mutex_unlock(&pool->pool_mutex);
	while (pool->keep_alive)
	{
		bsem_wait(&pool->jobs.has_jobs);
		if (pool->keep_alive)
		{
			pthread_mutex_lock(&pool->pool_mutex);
			pool->nb_th_working += 1;
			pthread_mutex_unlock(&pool->pool_mutex);
			exec_job(&pool->jobs);
			pthread_mutex_lock(&pool->pool_mutex);
			pool->nb_th_working -= 1;
			if (!pool->nb_th_working)
			{
				pthread_cond_signal(&pool->pool_cond);
			}
			pthread_mutex_unlock(&pool->pool_mutex);
		}
	}
	pthread_mutex_lock(&pool->pool_mutex);
	pool->nb_th_alive -= 1;
	pthread_mutex_unlock(&pool->pool_mutex);
	return (NULL);
}

static int	init_threads(t_thpool *pool, size_t nb_thread)
{
	size_t i;

	i = 0;
	while (i < nb_thread)
	{
		if (pthread_create(&pool->threads[i], NULL, (void *)thread_do, pool)
				|| pthread_detach(pool->threads[i]))
			return (0);
		i++;
	}
	return (1);
}

t_thpool	*thpool_init(size_t nb_thread)
{
	t_thpool *pool;

	if (!nb_thread || !(pool = (t_thpool *)malloc(sizeof(t_thpool))))
		return (NULL);
	if (!jobqueue_init(&pool->jobs)
	|| !(pool->threads = (pthread_t *)malloc(sizeof(pthread_t) * nb_thread)))
	{
		free(pool);
		return (NULL);
	}
	pool->keep_alive = 1;
	if (pthread_mutex_init(&pool->pool_mutex, NULL)
		|| pthread_cond_init(&pool->pool_cond, NULL)
		|| !init_threads(pool, nb_thread))
	{
		free(pool->threads);
		free(pool);
		return (NULL);
	}
	while (pool->nb_th_alive != nb_thread)
		;
	return (pool);
}
