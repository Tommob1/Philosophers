/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   protect_vars.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btomlins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 15:45:11 by btomlins          #+#    #+#             */
/*   Updated: 2024/08/09 15:04:28 by btomlins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

void    set_bool(t_mtx *mutex, bool *dst, bool value)
{
    handle_mutex(mutex, LOCK);
    *dst = value;
    handle_mutex(mutex, UNLOCK);
}

bool    get_bool(t_mtx *mutex, bool *value)
{

}

void    set_long(t_mtx *mutex, long *dst, long value)
{

}

long    get_long(t_mtx *mutex, long *value)
{
    
}