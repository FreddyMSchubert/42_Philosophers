/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: freddy <freddy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 11:19:26 by freddy            #+#    #+#             */
/*   Updated: 2024/01/15 11:44:49 by freddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philos.h"

#include <stdio.h>  // for printf
#include <unistd.h> // for usleep

int		philo_sleep(t_philo_inputs *philo_inputs)
{
	int		time_since_program_start;

	time_since_program_start = get_ms_timestamp() - philo_inputs->program_start_time;
	printf("%d\t%d is sleeping\n", time_since_program_start, philo_inputs->phid);
	usleep(philo_inputs->inputs.time_to_sleep * 1000);
	return (0);
}
