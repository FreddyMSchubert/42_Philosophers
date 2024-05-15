/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 16:58:11 by fschuber          #+#    #+#             */
/*   Updated: 2024/05/15 10:03:58 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philos.h"

int	set_death_flag(t_philo_inputs *inputs)
{
	pthread_mutex_lock(inputs->inputs.death_flag_mutex);
	if (get_death_flag(inputs) != 0)
	{
		pthread_mutex_unlock(inputs->inputs.death_flag_mutex);
		return (-1);
	}
	*(inputs->inputs.death_flag) = 1;
	pthread_mutex_unlock(inputs->inputs.death_flag_mutex);
	return (0);
}

int	get_death_flag(t_philo_inputs *inputs)
{
	int		death_flag;

	pthread_mutex_lock(inputs->inputs.death_flag_mutex);
	death_flag = *(inputs->inputs.death_flag);
	pthread_mutex_unlock(inputs->inputs.death_flag_mutex);
	return (death_flag);
}

void	die(t_philo_inputs *inputs)
{
	pthread_mutex_lock(inputs->inputs.death_flag_mutex);
	if (*(inputs->inputs.death_flag) == 0)
	{
		*(inputs->inputs.death_flag) = 1;
		log_philo_action(inputs, "died", "💀");
		pthread_mutex_unlock(inputs->inputs.death_flag_mutex);
		return ;
	}
	pthread_mutex_unlock(inputs->inputs.death_flag_mutex);
	return ;
}
