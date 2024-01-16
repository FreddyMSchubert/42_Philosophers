/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 08:58:27 by fschuber          #+#    #+#             */
/*   Updated: 2024/01/16 09:29:59 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// validates and computes command line input

#include "../philos.h"

int	manage_input(int argc, char **argv, t_inputs	*inputs)
{
	if (argc < 5 || argc > 6)
		return (-1);
	inputs->number_of_philosophers = ft_atoi(argv[1]);
	if (inputs->number_of_philosophers < 1)
		return (-1);
	inputs->time_to_die = ft_atoi(argv[2]);
	inputs->time_to_eat = ft_atoi(argv[3]);
	inputs->time_to_sleep = ft_atoi(argv[4]);
	if (inputs->time_to_die < 0 || \
		inputs->time_to_eat < 0 || \
		inputs->time_to_sleep < 0)
		return (-1);
	if (argv[5])
	{
		inputs->times_a_philo_must_eat = ft_atoi(argv[5]);
		if (inputs->times_a_philo_must_eat < 0)
			return (-1);
	}
	else
	{
		inputs->times_a_philo_must_eat = -1;
	}
	logger('l', "Input parameters are valid!");
	return (0);
}
