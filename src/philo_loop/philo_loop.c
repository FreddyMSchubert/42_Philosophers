/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 09:48:13 by fschuber          #+#    #+#             */
/*   Updated: 2024/05/10 10:06:43 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philos.h"

// Main loop for the philosopher threads

int	determine_first_philo_to_eat(t_philo_inputs *philo_inputs)
{
	int	time_to_sleep;

	time_to_sleep = 0;
	if (philo_inputs->inputs.number_of_philosophers % 2 == 0 && \
					philo_inputs->phid % 2 == 0)
		time_to_sleep = philo_inputs->inputs.time_to_eat / 5 * 4;
	else if (philo_inputs->phid % 3 > 0)
		time_to_sleep = philo_inputs->inputs.time_to_eat / 5 * 4 + \
				philo_inputs->phid % 3 * philo_inputs->inputs.time_to_eat;
	else
		philo_inputs->expected_eat_time = get_ms_timestamp();
	if (time_to_sleep > 0)
	{
		log_philo_action(philo_inputs, "is thinking");
		philo_inputs->expected_eat_time = get_ms_timestamp() + \
							philo_inputs->inputs.time_to_eat;
		ft_sleep(time_to_sleep);
	}
	return (philo_inputs->inputs.number_of_philosophers % 2);
}

// 0 = success, 1 = break, 2 = return
static int	execute_philo_action(t_philo_inputs *philo_inputs, \
				unsigned long *last_meal_time, int *times_eaten, \
				int *current_step)
{
	if (*philo_inputs->death_flag != 0)
		return (2);
	if (*current_step % 3 == 0)
	{
		if (philo_eat(philo_inputs, last_meal_time, times_eaten) != 0)
			return (1);
		if (*times_eaten >= philo_inputs->inputs.times_a_philo_must_eat && \
						philo_inputs->inputs.times_a_philo_must_eat > 0)
			return (2);
	}
	else if (*current_step % 3 == 1)
		philo_sleep(philo_inputs, *last_meal_time);
	else if (*current_step % 3 == 2)
		philo_think(philo_inputs, *last_meal_time);
	*current_step = *current_step + 1;
	*current_step = *current_step % 3;
	return (0);
}

void	*philo_loop(void *arg)
{
	t_philo_inputs	*philo_inputs;
	unsigned long	last_meal_time;
	int				times_eaten;
	int				current_step;
	int				ret_val;

	current_step = 0;
	philo_inputs = (t_philo_inputs *)arg;
	last_meal_time = get_ms_timestamp();
	times_eaten = 0;
	determine_first_philo_to_eat(philo_inputs);
	while (get_ms_timestamp() - last_meal_time < \
							(unsigned long)philo_inputs->inputs.time_to_die)
	{
		ret_val = execute_philo_action(philo_inputs, &last_meal_time, \
										&times_eaten, &current_step);
		if (ret_val == 1)
			break ;
		else if (ret_val == 2)
			return (NULL);
	}
	log_philo_action(philo_inputs, "died");
	*philo_inputs->death_flag = -1;
	return (NULL);
}
