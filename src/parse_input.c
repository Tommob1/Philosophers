/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btomlins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 15:45:19 by btomlins          #+#    #+#             */
/*   Updated: 2024/08/02 17:58:43 by btomlins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

static long ft_atol(const char *s)
{
    long    res;
    res = 0;
    while ((*s == '+' || *s == 32 || (*s >= 9 && *s <= 13)))
        s++;
    if (*s == '-')
        return (0);
    if (!(*s >= '0' && *s <= '9'))
    {
        error_msg("Input Error: Digit values only");
        return (0);
    }
    while (*s >= '0' && *s <= '9')
        res = (res * 10) + (*s++ - '0');
        return (res);
}

static long check_int_range(t_data *data, char *argv)
{
    long    input;
    input = ft_atol(argv);
    if (input > INT_MAX)
    {
        error_msg("Input Error: The value cannot exceed INT_MAX");
        data->error_flag = 1;
    }
}

void    parse_input(t_data *data, char **argv)
{

}
