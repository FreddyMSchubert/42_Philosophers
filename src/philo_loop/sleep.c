/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 11:19:26 by freddy            #+#    #+#             */
/*   Updated: 2024/05/15 12:23:35 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philos.h"

// if condition adjusts sleep time so philo doesn't forget to die while sleeping
int	philo_sleep(t_philo_inputs *philo_inputs, unsigned long last_meal_time)
{
	int		sleep_time;

	sleep_time = philo_inputs->inputs.time_to_sleep;
	if (last_meal_time + philo_inputs->inputs.time_to_die < \
		get_ms_timestamp() + philo_inputs->inputs.time_to_sleep)
	{
		sleep_time = last_meal_time + philo_inputs->inputs.time_to_die - \
						get_ms_timestamp();
	}
	if (get_death_flag(philo_inputs) != 0)
		return (1);
	log_philo_action(philo_inputs, "is sleeping", "💤");
	ft_sleep(sleep_time, philo_inputs, last_meal_time);
	return (0);
}
