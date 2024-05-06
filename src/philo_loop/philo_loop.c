/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 09:48:13 by fschuber          #+#    #+#             */
/*   Updated: 2024/05/06 13:36:59 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philos.h"

// Main loop for the philosopher threads

void	*philo_loop(void *arg)
{
	t_philo_inputs	*philo_inputs;
	unsigned long	last_meal_time;
	int				times_eaten;
	int				current_step;

	current_step = 0;
	philo_inputs = (t_philo_inputs *)arg;
	last_meal_time = get_ms_timestamp();
	times_eaten = 0;
	if (philo_inputs->phid % 2 == 1 && \
							philo_inputs->inputs.number_of_philosophers != 1)
	{
		log_philo_action(philo_inputs, "is thinking");
		usleep(philo_inputs->inputs.time_to_eat * 1000);
	}
	while (get_ms_timestamp() - last_meal_time < \
							(unsigned long)philo_inputs->inputs.time_to_die)
	{
		if (*philo_inputs->death_flag != 0)
			return (NULL);
		if (current_step % 3 == 0)
		{
			if (philo_eat(philo_inputs, &last_meal_time, &times_eaten) != 0)
				break ;
			if (times_eaten >= philo_inputs->inputs.times_a_philo_must_eat && \
								philo_inputs->inputs.times_a_philo_must_eat > 0)
				return (NULL);
		}
		else if (current_step % 3 == 1)
			philo_sleep(philo_inputs, last_meal_time);
		else if (current_step % 3 == 2)
			philo_think(philo_inputs);
		current_step++;
		if (current_step >= 3)
			current_step = 0;
	}
	log_philo_action(philo_inputs, "died");
	*philo_inputs->death_flag = -1;
	return (NULL);
}
