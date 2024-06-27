/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btomlins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 16:26:10 by btomlins          #+#    #+#             */
/*   Updated: 2024/06/27 13:51:06 by btomlins         ###   ########.fr       */
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

#endif
