/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btomlins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 15:46:11 by btomlins          #+#    #+#             */
/*   Updated: 2024/08/14 13:52:41 by btomlins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

void	error_msg(const char	*error_msg)
{
	printf(RED "%s\n" RESET, error_msg);
}

void	*ft_malloc(size_t bytes)
{
	void	*retrieve;

	retrieve = malloc(bytes);
	if (retrieve == NULL)
	{
		error_msg("Memory allocation unsuccessful");
		return (NULL);
	}
	return (retrieve);
}

long	gettime(t_time_unit time_unit)
{
	struct timeval	current_time;

	if (gettimeofday(&current_time, NULL) != 0)
	{
		error_msg("Error: gettimeofday failed");
		return (1);
	}
	if (time_unit == MILLISECONDS)
		return (current_time.tv_sec * 1000 + current_time.tv_usec / 1000);
	else if (time_unit == MICROSECONDS)
		return (current_time.tv_sec * 1000000 + current_time.tv_usec);
	else if (time_unit == SECONDS)
		return (current_time.tv_sec + current_time.tv_usec / 1000000);
	else
	{
		error_msg("INVALID TIME UNIT SPECIFIED");
		return (1);
	}
	return (-1);
}

void	ft_usleep(long sleep_time, t_data *data)
{
	long	start;
	long	elapsed;
	long	remaining;

	start = gettime(MICROSECONDS);
	while (gettime(MICROSECONDS))
	{
		if (get_bool(&data->access_mutex, &data->end_time))
			break ;
		elapsed = gettime(MICROSECONDS) - start;
		remaining = sleep_time - elapsed;
		if (remaining > 10000)
			usleep(remaining / 2);
		else
			while (gettime(MICROSECONDS) - start < sleep_time)
				;
	}
}

void	free_things(t_data *data)
{
	t_ph	*philo;
	int		i;

	i = 0;
	while (i < data->ph_total)
	{
		philo = data->philos_arr + i;
		handle_mutex(&philo->ph_mutex, DESTROY);
		i++;
	}
	handle_mutex(&data->write_mutex, DESTROY);
	handle_mutex(&data->access_mutex, DESTROY);
	free(data->forks_arr);
	free(data->philos_arr);
}
