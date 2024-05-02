/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 11:19:26 by freddy            #+#    #+#             */
/*   Updated: 2024/05/02 12:07:15 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philos.h"

// if condition adjusts sleep time so philo doesn't forget to die while sleeping
int	philo_sleep(t_philo_inputs *philo_inputs, unsigned long last_meal_time)
{
	int		sleep_time;

	sleep_time = philo_inputs->inputs.time_to_sleep * 1000;
	if (last_meal_time + philo_inputs->inputs.time_to_die < \
		get_ms_timestamp() + philo_inputs->inputs.time_to_sleep)
	{
		sleep_time = last_meal_time + philo_inputs->inputs.time_to_die - \
						get_ms_timestamp();
	}
	log_philo_action(get_ms_timestamp() - philo_inputs->program_start_time, \
						philo_inputs->phid, "is sleeping");
	usleep(sleep_time);
	return (0);
}
