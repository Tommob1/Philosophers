/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btomlins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 14:11:27 by btomlins          #+#    #+#             */
/*   Updated: 2024/07/03 15:45:34 by btomlins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

void    wait_all_threads(t_data *data)
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