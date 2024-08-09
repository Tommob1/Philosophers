/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btomlins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 15:45:17 by btomlins          #+#    #+#             */
/*   Updated: 2024/08/09 14:14:58 by btomlins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

void    ph_status(t_ph_status status, t_ph *philo)
{
    long    elapsed;
    bool    end_time;

    elapsed = gettime(MILLISECONDS) - philo->data->start_time;
    if (get_bool(&philo->ph_mutex, &philo->max_meals))
        return ;
    else
    {
        
    }
}