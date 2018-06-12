/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thpool_destroy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 14:58:11 by mdeville          #+#    #+#             */
/*   Updated: 2018/06/12 15:15:02 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdlib.h>
#include "thpool.h"

void	thpool_destroy(t_thpool *pool)
{
	pool->keep_alive = 0;
	while (pool->nb_th_alive)
		bsem_post_all(&pool->jobs.has_jobs);
	free(pool->threads);
	free(pool);
}
