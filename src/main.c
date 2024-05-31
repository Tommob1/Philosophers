/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btomlins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 16:21:56 by btomlins          #+#    #+#             */
/*   Updated: 2024/05/31 14:46:12 by btomlins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

int	main(int argc,  char **argv)
{
	t_data  data;

    if (argc == 5 || argc == 6)
    {
        data.error_flag = 0;
        parse_input(&data, argv);
        if (!data.error_flag)
        {
            data_init(&data);
            sim_start(&data);
            free_things(&data);
        }
        else
            return (1);
    }
    else
		error_msg("Input Error\n""Please enter: ./philo <no. of philos> <time_to_die> "
			"<time_to_eat> <time_to_sleep> <max_meals> (optional)\n"
			"For example: ./philo 5 800 200 200 7" RESET);
    return (0);
}
