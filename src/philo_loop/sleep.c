/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 11:19:26 by freddy            #+#    #+#             */
/*   Updated: 2024/01/16 09:35:19 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philos.h"

#include <stdio.h>  // for printf
#include <unistd.h> // for usleep

int	philo_sleep(t_philo_inputs *philo_inputs)
{
	log_philo_action(get_ms_timestamp() - philo_inputs->program_start_time, \
						philo_inputs->phid, "is sleeping");
	usleep(philo_inputs->inputs.time_to_sleep * 1000);
	return (0);
}
