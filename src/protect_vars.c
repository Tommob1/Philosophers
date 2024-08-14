/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   protect_vars.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btomlins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 15:45:11 by btomlins          #+#    #+#             */
/*   Updated: 2024/08/14 12:45:49 by btomlins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

void	set_bool(t_mtx *mutex, bool *dst, bool value)
{
	handle_mutex(mutex, LOCK);
	*dst = value;
	handle_mutex(mutex, UNLOCK);
}

bool	get_bool(t_mtx *mutex, bool *value)
{
	bool	retrieved;

	handle_mutex(mutex, LOCK);
	retrieved = *value;
	handle_mutex(mutex, UNLOCK);
	return (retrieved);
}

void	set_long(t_mtx *mutex, long *dst, long value)
{
	handle_mutex(mutex, LOCK);
	*dst = value;
	handle_mutex(mutex, UNLOCK);
}

long	get_long(t_mtx *mutex, long *value)
{
	long	retrieve;

	handle_mutex(mutex, LOCK);
	retrieve = *value;
	handle_mutex(mutex, UNLOCK);
	return (retrieve);
}
