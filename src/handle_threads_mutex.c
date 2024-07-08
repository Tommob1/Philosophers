/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_threads_mutex.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btomlins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 15:45:25 by btomlins          #+#    #+#             */
/*   Updated: 2024/07/08 16:15:14 by btomlins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

static void	mutex_error_check(int status, t_ftcode ftcode)
{
	if (status != 0 && (ftcode == LOCK || ftcode == UNLOCK
			|| ftcode == INIT || ftcode == DESTROY))
	{
			error_msg("Metex error");
			return ;
	}
}

void	handle_mutex(t_mtx *mtx, t_ftcode ftcode)
{
	if (ftcode == LOCK)
		mutex_error_check(pthread_mutex_lock(mtx), ftcode);
	else if (ftcode == UNLOCK)
		mutex_error_check(pthread_mutex_unlock(mtx), ftcode);
	else if (ftcode == INIT)
		mutex_error_check(pthread_mutex_init(mtx, NULL), ftcode);
	else if (ftcode == DESTROY)
		mutex_error_check(pthread_mutex_destroy(mtx), ftcode);
	else
	{
		error_msg("ftcode options: LOCK, UNLOCK, INIT, DESTROY");
		return ;
	}
}
