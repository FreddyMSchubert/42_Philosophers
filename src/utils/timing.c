/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timing.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 10:20:58 by freddy            #+#    #+#             */
/*   Updated: 2024/05/08 08:11:27 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philos.h"

// functions related to time tracking the program

unsigned long	get_ms_timestamp(void)
{
	struct timeval		tv;
	unsigned long		time_in_ms;

	gettimeofday(&tv, NULL);
	time_in_ms = 1000 * tv.tv_sec + tv.tv_usec / 1000;
	return (time_in_ms);
}

void	ft_sleep(unsigned long ms)
{
	unsigned long	start_time;

	start_time = get_ms_timestamp();
	while (get_ms_timestamp() - start_time < ms)
		usleep(100);
}
