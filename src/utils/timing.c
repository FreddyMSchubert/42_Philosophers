/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timing.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: freddy <freddy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 10:20:58 by freddy            #+#    #+#             */
/*   Updated: 2024/01/15 10:37:21 by freddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// functions related to time tracking the program

#include "sys/time.h"

unsigned long	get_ms_timestamp(void)
{
	struct timeval		tv;
	unsigned long		time_in_millis;

	gettimeofday(&tv, NULL);
	time_in_millis = 1000 * tv.tv_sec + tv.tv_usec / 1000;
	return (time_in_millis);
}
