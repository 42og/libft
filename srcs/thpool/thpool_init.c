/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thpool_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 18:04:13 by mdeville          #+#    #+#             */
/*   Updated: 2018/06/11 19:27:53 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "dlst.h"
#include "thpool.h"

static int	jobqueue_init(t_jobqueue *jobs)
{
	if (!pthread_mutex_init(&jobs->job_mutex, NULL))
		return (0);
	jobs->front = NULL;
	jobs->back = NULL;
	jobs->len = 0;
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
	
	return (pool);
}
