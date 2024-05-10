/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 11:18:14 by freddy            #+#    #+#             */
/*   Updated: 2024/05/10 09:55:23 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philos.h"

static bool	dead(t_philo_inputs *philo_inputs, \
				unsigned long *last_meal_time, pthread_mutex_t *fork)
{
	if (get_ms_timestamp() - *last_meal_time >= \
			(unsigned long)philo_inputs->inputs.time_to_die)
	{
		*philo_inputs->death_flag = -1;
		if (fork != NULL)
			pthread_mutex_unlock(fork);
		return (true);
	}
	if (*philo_inputs->death_flag != 0)
	{
		if (fork != NULL)
			pthread_mutex_unlock(fork);
		return (true);
	}
	return (false);
}

static bool	wait_until_eat_time(t_philo_inputs *philo_inputs, \
				unsigned long *last_meal_time)
{
	unsigned long	current_time;

	current_time = get_ms_timestamp();
	while (current_time < philo_inputs->expected_eat_time - \
							get_eat_start_softness(philo_inputs))
	{
		if (dead(philo_inputs, last_meal_time, NULL))
			return (false);
		ft_sleep(100);
		current_time = get_ms_timestamp();
	}
	return (true);
}

static int	determine_fork_order(t_philo_inputs *philo_inputs, \
				int *fork1, int *fork2)
{
	*fork1 = philo_inputs->phid;
	*fork2 = philo_inputs->phid + 1;
	if (philo_inputs->phid % 2 == 0)
	{
		*fork2 = philo_inputs->phid;
		*fork1 = philo_inputs->phid + 1;
	}
	if (*fork2 == philo_inputs->inputs.number_of_philosophers)
		*fork2 = 0;
	if (*fork1 == philo_inputs->inputs.number_of_philosophers)
		*fork1 = 0;
	if (*fork1 == *fork2)
		return (-1);
	return (0);
}

static void	eat(t_philo_inputs *philo_inputs, \
				unsigned long *last_meal_time, int *times_eaten)
{
	log_philo_action(philo_inputs, "is eating");
	*last_meal_time = get_ms_timestamp();
	ft_sleep(philo_inputs->inputs.time_to_eat);
	*times_eaten += 1;
}

int	philo_eat(t_philo_inputs *philo_inputs, \
				unsigned long *last_meal_time, int *times_eaten)
{
	int		fork1;
	int		fork2;

	if (philo_inputs->inputs.number_of_philosophers == 1)
		return (ft_sleep(philo_inputs->inputs.time_to_die), -1);
	if (wait_until_eat_time(philo_inputs, last_meal_time) == false)
		return (-1);
	if (determine_fork_order(philo_inputs, &fork1, &fork2) == -1)
		return (-1);
	pthread_mutex_lock(philo_inputs->inputs.forks[fork1]);
	log_philo_action(philo_inputs, "has taken a fork");
	if (dead(philo_inputs, last_meal_time, philo_inputs->inputs.forks[fork1]))
		return (-1);
	pthread_mutex_lock(philo_inputs->inputs.forks[fork2]);
	log_philo_action(philo_inputs, "has taken a fork");
	if (dead(philo_inputs, last_meal_time, philo_inputs->inputs.forks[fork1]))
		return (-1);
	eat(philo_inputs, last_meal_time, times_eaten);
	pthread_mutex_unlock(philo_inputs->inputs.forks[fork1]);
	log_detailed_philo_action(philo_inputs, "has put down a fork");
	pthread_mutex_unlock(philo_inputs->inputs.forks[fork2]);
	log_detailed_philo_action(philo_inputs, "has put down a fork");
	return (0);
}
