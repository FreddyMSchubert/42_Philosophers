/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: freddy <freddy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 09:48:13 by fschuber          #+#    #+#             */
/*   Updated: 2024/01/15 12:41:41 by freddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philos.h"

#include <stdio.h> // for printf

// Main loop for the philosopher threads

void	*philo_loop(void *arg)
{
	t_philo_inputs	*philo_inputs;
	unsigned long	last_meal_time;
	int				times_eaten;
	int				first_run;

	philo_inputs = (t_philo_inputs *)arg;
	last_meal_time = philo_inputs->program_start_time;
	times_eaten = 0;
	first_run = 1;
	while (get_ms_timestamp() - last_meal_time < (unsigned long)philo_inputs->inputs.time_to_die)
	{
		if (first_run == 1 && philo_inputs->phid % 2 == 0)
		{
			philo_think(philo_inputs);
			first_run = 0;
		}
		philo_eat(philo_inputs, &last_meal_time, &times_eaten);
		philo_sleep(philo_inputs);
		philo_think(philo_inputs);
		if (times_eaten >= philo_inputs->inputs.number_of_times_each_philosopher_must_eat)
		{
			return (NULL);
		}
	}
	printf("%lu\t%d died\n", get_ms_timestamp() - philo_inputs->program_start_time, philo_inputs->phid);
	// set the shared flag negative, that basically replaces return value
	return (NULL);
}
