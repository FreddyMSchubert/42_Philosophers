/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 09:48:13 by fschuber          #+#    #+#             */
/*   Updated: 2024/01/16 09:55:59 by fschuber         ###   ########.fr       */
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

	philo_inputs = (t_philo_inputs *)arg;
	last_meal_time = philo_inputs->program_start_time;
	times_eaten = 0;
	if (philo_inputs->phid % 2 == 0)
		philo_think(philo_inputs);
	while (get_ms_timestamp() - last_meal_time < \
							(unsigned long)philo_inputs->inputs.time_to_die)
	{
		if (*philo_inputs->death_flag != 0)
			return (NULL);
		philo_eat(philo_inputs, &last_meal_time, &times_eaten);
		if (times_eaten >= philo_inputs->inputs.times_a_philo_must_eat && \
								philo_inputs->inputs.times_a_philo_must_eat > 0)
			return (NULL);
		philo_sleep(philo_inputs);
		philo_think(philo_inputs);
	}
	log_philo_action(get_ms_timestamp() - philo_inputs->program_start_time, \
							philo_inputs->phid, "died");
	*philo_inputs->death_flag = -1;
	return (NULL);
}
