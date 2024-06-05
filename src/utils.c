/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btomlins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 15:46:11 by btomlins          #+#    #+#             */
/*   Updated: 2024/06/05 15:50:42 by btomlins         ###   ########.fr       */
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
