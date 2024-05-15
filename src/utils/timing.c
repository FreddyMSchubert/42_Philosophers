/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timing.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 10:20:58 by freddy            #+#    #+#             */
/*   Updated: 2024/05/15 08:29:24 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philos.h"

// functions related to time tracking the program

unsigned long	get_ms_timestamp(void)
{
	struct timeval		tv;
	unsigned long		time_in_ms;

	gettimeofday(&tv, NULL);
	time_in_ms = 1000 * tv.tv_sec + tv.tv_usec / 1000;
	return (time_in_ms);
}

void	ft_sleep(unsigned long ms, t_philo_inputs *philo_inputs)
{
	unsigned long	start_time;

	start_time = get_ms_timestamp();
	while (get_ms_timestamp() - start_time < ms)
	{
		usleep(100);
		if (get_death_flag(philo_inputs) != 0)
			return ;
	}
}

int	get_eat_start_softness(t_philo_inputs *philo_inputs)
{
	int	shortest_action_time;

	shortest_action_time = philo_inputs->inputs.time_to_eat;
	if (philo_inputs->inputs.time_to_sleep < shortest_action_time)
		shortest_action_time = philo_inputs->inputs.time_to_sleep;
	return (shortest_action_time / 2);
}
