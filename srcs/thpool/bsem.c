/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsem.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 14:53:26 by mdeville          #+#    #+#             */
/*   Updated: 2018/09/10 14:57:33 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdlib.h>
#include "thpool.h"

void	bsem_wait(t_bsem *bsem_p)
{
	pthread_mutex_lock(&bsem_p->mutex);
	while (bsem_p->v != 1)
	{
		pthread_cond_wait(&bsem_p->cond, &bsem_p->mutex);
	}
	bsem_p->v = 0;
	pthread_mutex_unlock(&bsem_p->mutex);
}

void	bsem_post(t_bsem *bsem_p)
{
	pthread_mutex_lock(&bsem_p->mutex);
	bsem_p->v = 1;
	pthread_cond_signal(&bsem_p->cond);
	pthread_mutex_unlock(&bsem_p->mutex);
}

void	bsem_post_all(t_bsem *bsem_p)
{
	pthread_mutex_lock(&bsem_p->mutex);
	bsem_p->v = 1;
	pthread_cond_broadcast(&bsem_p->cond);
	pthread_mutex_unlock(&bsem_p->mutex);
}
