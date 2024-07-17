/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btomlins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 15:45:27 by btomlins          #+#    #+#             */
/*   Updated: 2024/07/17 14:52:56 by btomlins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

void	*single_philo(void *index)
{
	t_ph	*philo;

	philo = (t_ph *)index;
	wait_all_threads(philo->data);
	set_long(&philo->ph_mutex, &philo->meal_time, gettime(MILLISECONDS));
	active_thread_counter(&philo->data->access_mutex, &philo->data->active_philos_count);
	ph_status(TAKES_LEFTFORK, philo);
	while (!get_bool(&philo->data->access_mutex, &philo->data->end_time))
		ft_usleep(200, philo->data);
	return(NULL);
}

static void	assign_forks(t_ph *philo, t_fork *forks_arr, int ph_index)
{
	int	ph_total;

	ph_total = philo->data->ph_total;
	if (philo->ph_id % 2 != 0)
	{
		philo->left_fork = &forks_arr[(ph_index + 1) % ph_total];
		philo->right_fork = &forks_arr[ph_index];
	}
	if (philo->ph_id % 2 == 0)
	{
		philo->left_fork = &forks_arr[ph_index];
		philo->right_fork = &forks_arr[(ph_index + 1) % ph_total];
	}
}

static void	philo_init(t_data *data)
{

}

void	data_init(t_data *data)
{
	
}
