/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btomlins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 15:45:19 by btomlins          #+#    #+#             */
/*   Updated: 2024/08/14 13:54:21 by btomlins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

static long	ft_atol(const char *s)
{
	long	res;
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

static long	check_int_range(t_data *data, char *argv)
{
	long	input;
	input = ft_atol(argv);
	if (input > INT_MAX)
	{
		error_msg("Input Error: The value cannot exceed INT_MAX");
		data->error_flag = 1;
	}
	if (input < 1)
	{
		error_msg("Input Error: Positive values only");
		data->error_flag = 1;
	}
	return (input);
}

void	parse_input(t_data *data, char **argv)
{
	data->ph_total = check_int_range(data, argv[1]);
	if (data->ph_total > PH_MAX || data->ph_total < 1)
	{
		error_msg("Input Error: Total number of philos must be 1-200");
		data->error_flag = 1;
	}
	data->time_to_die = check_int_range(data, argv[2]) * 1000;
	data->time_to_eat = check_int_range(data, argv[3]) * 1000;
	data->time_to_sleep = check_int_range(data, argv[4]) * 1000;

	if (data->time_to_die < 60000 || data->time_to_sleep < 60000 || data->time_to_eat < 60000)
	{
		error_msg("Input Error: Each of the 'time_to' values must exceed 60");
		data->error_flag = 1;
	}
	if (argv[5])
		data->meals_total = check_int_range(data, argv[5]);
	else
		data->meals_total = -1;
}
