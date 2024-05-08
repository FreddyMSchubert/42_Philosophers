/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 11:18:14 by freddy            #+#    #+#             */
/*   Updated: 2024/05/07 10:21:34 by fschuber         ###   ########.fr       */
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
	if (*philo_inputs->death_flag != 0)
	{
		if (fork1 != NULL)
			pthread_mutex_unlock(fork1);
		if (fork2 != NULL)
			pthread_mutex_unlock(fork2);
		return (true);
	}
	return (false);
}

int	get_eat_start_softness(t_philo_inputs *philo_inputs)
{
	int	shortest_action_time;

	shortest_action_time = philo_inputs->inputs.time_to_eat;
	if (philo_inputs->inputs.time_to_sleep < shortest_action_time)
		shortest_action_time = philo_inputs->inputs.time_to_sleep;
	return (shortest_action_time / 2);
}

bool	wait_until_eat_time(t_philo_inputs *philo_inputs, \
				unsigned long *last_meal_time)
{
	unsigned long	current_time;

	current_time = get_ms_timestamp();
	while (current_time < philo_inputs->expected_eat_time - get_eat_start_softness(philo_inputs))
	{
		if (check_is_dead(philo_inputs, last_meal_time, NULL, NULL))
			return (false);
		ft_sleep(100);
		current_time = get_ms_timestamp();
	}
	return (true);
}

int	philo_eat(t_philo_inputs *philo_inputs, \
				unsigned long *last_meal_time, \
				int *times_eaten)
{
	int		fork1;
	int		fork2;

	if (philo_inputs->inputs.number_of_philosophers == 1)
		return (usleep(philo_inputs->inputs.time_to_die * 1000), -1);
	if (wait_until_eat_time(philo_inputs, last_meal_time) == false)
		return (-1);
	fork1 = philo_inputs->phid;
	fork2 = philo_inputs->phid + 1;
	if (philo_inputs->phid % 2 == 0)
	{
		fork2 = philo_inputs->phid;
		fork1 = philo_inputs->phid + 1;
	}
	if (fork2 == philo_inputs->inputs.number_of_philosophers)
		fork2 = 0;
	if (fork1 == philo_inputs->inputs.number_of_philosophers)
		fork1 = 0;
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
	*last_meal_time = get_ms_timestamp();
	ft_sleep(philo_inputs->inputs.time_to_eat);
	*times_eaten += 1;
	pthread_mutex_unlock(philo_inputs->inputs.forks[fork1]);
	if (DETAILEDMESSAGES)
		log_philo_action(philo_inputs, "has put down a fork");
	pthread_mutex_unlock(philo_inputs->inputs.forks[fork2]);
	if (DETAILEDMESSAGES)
		log_philo_action(philo_inputs, "has put down a fork");
	return (0);
}
