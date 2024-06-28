/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btomlins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 16:26:10 by btomlins          #+#    #+#             */
/*   Updated: 2024/06/28 22:55:28 by btomlins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <pthread.h>
# include <sys/time.h>
# include <limits.h>

# define PH_MAX 200

# define RESET  "\033[0m"
# define RED    "\033[1;31m"
# define GREEN  "\033[1;32"

typedef struct s_data	t_data;

typedef pthread_mutex_t	t_mtx;

typedef struct s_fork
{
	t_mtx	fork_mutex;
	int		fork_id;
}			t_fork;

typedef struct s_ph
{

}		t_data;

typedef struct s_data
{
	long		ph_total;
	long		time_to_die;
	long		time_to_eat;
	long		time_to_sleep;
	long		meals_total;
	long		start_time;
	long		end_time;
	bool		error_flag;
	pthread_t	death_check;
}			t_data;

typedef enum	e_time_unit
{
	SECONDS,
	MILLISECONDS,
	MICROSECONDS,
}			t_time_unit;

typedef enum	e_ftcode
{
	INIT,
	CREATE,
	LOCK,
	UNLOCK,
	JOIN,
	DETACH,
	DESTROY,
}				t_ftcode;

void		handle_mutex(t_mtx *mutex, bool *dst, bool value);
void		handle_thread(pthread_t *thread_info, void*(*foo)(void *), void *t_data, t_ftcode ftcode);

#endif
