/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: freddy <freddy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 11:18:14 by freddy            #+#    #+#             */
/*   Updated: 2024/01/15 12:34:43 by freddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philos.h"

#include <stdio.h>  // for printf
#include <unistd.h> // for usleep

int		philo_eat(t_philo_inputs *philo_inputs, unsigned long *last_meal_time, int *times_eaten)
{
	if (VERBOSE == 1)
		printf("%d is starting eat attempt.\n", philo_inputs->phid);
	pthread_mutex_lock(&philo_inputs->forks[philo_inputs->phid]);
	printf("%lu\t%d has taken a fork\n", get_ms_timestamp() - philo_inputs->program_start_time, philo_inputs->phid);
	pthread_mutex_lock(&philo_inputs->forks[philo_inputs->phid + 1]);
	printf("%lu\t%d has taken a fork\n", get_ms_timestamp() - philo_inputs->program_start_time, philo_inputs->phid);
	printf("%lu\t%d is eating\n", get_ms_timestamp() - philo_inputs->program_start_time, philo_inputs->phid);
	usleep(philo_inputs->inputs.time_to_eat * 1000);
	*last_meal_time = get_ms_timestamp();
	*times_eaten += 1;
	pthread_mutex_unlock(&philo_inputs->forks[philo_inputs->phid]);
	pthread_mutex_unlock(&philo_inputs->forks[philo_inputs->phid + 1]);
	if (VERBOSE == 1)
		printf("%d is done eating.\n", philo_inputs->phid);
	return (0);
}
