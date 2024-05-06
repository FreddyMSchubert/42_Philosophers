/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 11:18:14 by freddy            #+#    #+#             */
/*   Updated: 2024/05/06 09:34:56 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philos.h"

int	philo_eat(t_philo_inputs *philo_inputs, \
				unsigned long *last_meal_time, \
				int *times_eaten)
{
	int		fork1;
	int		fork2;

	fork1 = philo_inputs->phid;
	fork2 = philo_inputs->phid + 1;
	if (fork2 == philo_inputs->inputs.number_of_philosophers)
		fork2 = 0;
	if (fork1 == fork2)
		return (-1);
	pthread_mutex_lock(philo_inputs->inputs.forks[fork1]);
	log_philo_action(philo_inputs, "has taken a fork");
	pthread_mutex_lock(philo_inputs->inputs.forks[fork2]);
	log_philo_action(philo_inputs, "has taken a fork");
	log_philo_action(philo_inputs, "is eating");
	usleep(philo_inputs->inputs.time_to_eat * 1000);
	*last_meal_time = get_ms_timestamp();
	*times_eaten += 1;
	pthread_mutex_unlock(philo_inputs->inputs.forks[fork1]);
	pthread_mutex_unlock(philo_inputs->inputs.forks[fork2]);
	return (0);
}
