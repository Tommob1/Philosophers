/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sim_start.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btomlins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 14:10:20 by btomlins          #+#    #+#             */
/*   Updated: 2024/08/14 16:04:51 by btomlins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

static void thinking(t_ph *philo, bool pre_simulation)
{
	long	eating_time;
	long	sleeping_time;
	long	thinking_time;

	if (!pre_simulation)
		ph_status(THINKING, philo);
	if (philo->data->ph_total % 2 == 0)
		return ;
	eating_time = philo->data->time_to_eat;
	sleeping_time = philo->data->time_to_sleep;
	thinking_time = (eating_time * 2) - sleeping_time;
	if (thinking_time < 0)
		thinking_time = 0;
	ft_usleep(thinking_time * 0.3, philo->data);
}

static void synchronize_dining(t_ph *philo)
{

}

static void eating(t_ph *philo)
{

}

static void *dining_philos(void *ph_data)
{

}

void    sim_start(t_data *data)
{

}
