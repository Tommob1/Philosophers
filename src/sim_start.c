/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sim_start.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btomlins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 14:10:20 by btomlins          #+#    #+#             */
/*   Updated: 2024/08/14 17:35:49 by btomlins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

static void	thinking(t_ph *philo, bool pre_simulation)
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

static void	synchronize_dining(t_ph *philo)
{
	if (philo->ph_id % 2 == 0)
		ft_usleep(30000, philo->data);
	else
		thinking(philo, true);
}

static void	eating(t_ph *philo)
{
	handle_mutex(&philo->left_fork->fork_mutex, LOCK);
	ph_status(TAKES_LEFTFORK, philo);
	handle_mutex(&philo->right_fork->fork_mutex, LOCK);
	ph_status(TAKES_RIGHTFORK, philo);
	set_long(&philo->ph_mutex, &philo->meal_time, gettime(MILLISECONDS));
	philo->meal_count++;
	ph_status(EATING, philo);
	ft_usleep(philo->data->time_to_eat, philo->data);
	if (philo->data->meals_total > 0 && philo->meal_count == philo->data
		->meals_total)
		set_bool(&philo->ph_mutex, &philo->max_meals, true);
	handle_mutex(&philo->left_fork->fork_mutex, UNLOCK);
	handle_mutex(&philo->right_fork->fork_mutex, UNLOCK);
}

static void	*dining_philos(void *ph_data)
{

}

void	sim_start(t_data *data)
{

}
