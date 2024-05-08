/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   think.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 11:22:43 by freddy            #+#    #+#             */
/*   Updated: 2024/05/08 08:58:09 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philos.h"

static void	calculate_expected_eat_time(t_philo_inputs *philo_inputs, unsigned long last_meal_time)
{
	int	one_cycle_time;

	if (philo_inputs->inputs.number_of_philosophers % 2 == 0)
	{
		if (philo_inputs->inputs.time_to_eat > philo_inputs->inputs.time_to_sleep)
			one_cycle_time = philo_inputs->inputs.time_to_eat * 2;
		else
			one_cycle_time = philo_inputs->inputs.time_to_sleep * 2;
	}
	else
	{
		if (philo_inputs->inputs.time_to_eat > philo_inputs->inputs.time_to_sleep)
			one_cycle_time = philo_inputs->inputs.time_to_eat * 3;
		else
			one_cycle_time = philo_inputs->inputs.time_to_sleep * 3;
	}
	if (philo_inputs->inputs.number_of_philosophers == 1)
		one_cycle_time = philo_inputs->inputs.time_to_eat;
	philo_inputs->expected_eat_time = last_meal_time + one_cycle_time;
	printf("philo %d: expected eat time: %lu, last eat time: %lu\n", philo_inputs->phid, philo_inputs->expected_eat_time - philo_inputs->inputs.program_start_time, last_meal_time - philo_inputs->inputs.program_start_time);
}

int	philo_think(t_philo_inputs *philo_inputs, unsigned long last_meal_time)
{
	log_philo_action(philo_inputs, "is thinking");
	calculate_expected_eat_time(philo_inputs, last_meal_time);
	return (0);
}
