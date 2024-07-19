/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btomlins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 14:11:27 by btomlins          #+#    #+#             */
/*   Updated: 2024/07/19 14:17:23 by btomlins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

void	wait_all_threads(t_data *data)
{
    while (!get_bool(&data->access_mutex, &data->threads_ready))
            ;
}

void    active_thread_counter(t_mtx *mutex, long *value)
{
    handle_mutex(mutex, LOCK);
    (*value)++;
    handle_mutex(mutex, UNLOCK);
}

static bool philo_died(t_ph *philo)
{
    long    elapsed;
    long    dying_time;

    if (get_bool(&philo->ph_mutex, &philo->max_meals))
            return (false);
    elapsed = gettime(MILLISECONDS) - get_long(&philo->ph_mutex, &philo->meal_time);
    dying_time = philo->data->time_to_die / 1000;
    if (elapsed > dying_time)
            return (true);
    return (false);
}

static bool all_philos_active(t_mtx *mutex, long *threads, long ph_total)
{
    bool    value;

    value = false;
    handle_mutex(mutex, LOCK);
    if (*threads == ph_total)
            value = true;
    handle_mutex(mutex, UNLOCK);
    return (value);
}

void    *death_affirm(void *ph_data)
{

}
