/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btomlins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 15:46:11 by btomlins          #+#    #+#             */
/*   Updated: 2024/07/29 17:23:03 by btomlins         ###   ########.fr       */
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
}

void	ft_usleep(long sleep_time, t_data *data)
{

}

void	free_things(t_data *data)
{
	
}
