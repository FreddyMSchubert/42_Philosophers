/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timing.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 10:20:58 by freddy            #+#    #+#             */
/*   Updated: 2024/05/02 11:53:32 by fschuber         ###   ########.fr       */
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
