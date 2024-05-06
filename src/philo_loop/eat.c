/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 11:18:14 by freddy            #+#    #+#             */
/*   Updated: 2024/05/06 10:41:08 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philos.h"

bool	check_is_dead(t_philo_inputs *philo_inputs, \
				unsigned long *last_meal_time, pthread_mutex_t *fork1,
				pthread_mutex_t *fork2)
{
	if (get_ms_timestamp() - *last_meal_time >= \
			(unsigned long)philo_inputs->inputs.time_to_die)
	{
		*philo_inputs->death_flag = -1;
		if (fork1 != NULL)
			pthread_mutex_unlock(fork1);
		if (fork2 != NULL)
			pthread_mutex_unlock(fork2);
		return (true);
	}
	return (false);
}

int	philo_eat(t_philo_inputs *philo_inputs, \
				unsigned long *last_meal_time, \
				int *times_eaten)
{
	int		fork1;
	int		fork2;

	if (philo_inputs->inputs.number_of_philosophers == 1)
		return (*philo_inputs->death_flag = -1, -1);
	fork1 = philo_inputs->phid;
	fork2 = philo_inputs->phid + 1;
	if (fork2 == philo_inputs->inputs.number_of_philosophers)
		fork2 = 0;
	if (fork1 == fork2)
		return (-1);
	pthread_mutex_lock(philo_inputs->inputs.forks[fork1]);
	log_philo_action(philo_inputs, "has taken a fork");
	if (check_is_dead(philo_inputs, last_meal_time, \
		philo_inputs->inputs.forks[fork1], NULL))
		return (-1);
	pthread_mutex_lock(philo_inputs->inputs.forks[fork2]);
	log_philo_action(philo_inputs, "has taken a fork");
	if (check_is_dead(philo_inputs, last_meal_time, \
		philo_inputs->inputs.forks[fork1], NULL))
		return (-1);
	log_philo_action(philo_inputs, "is eating");
	usleep(philo_inputs->inputs.time_to_eat * 1000);
	*last_meal_time = get_ms_timestamp();
	*times_eaten += 1;
	pthread_mutex_unlock(philo_inputs->inputs.forks[fork1]);
	if (DETAILEDMESSAGES)
		log_philo_action(philo_inputs, "has put down a fork");
	pthread_mutex_unlock(philo_inputs->inputs.forks[fork2]);
	if (DETAILEDMESSAGES)
		log_philo_action(philo_inputs, "has put down a fork");
	return (0);
}
