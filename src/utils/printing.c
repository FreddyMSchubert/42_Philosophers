/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 09:11:07 by fschuber          #+#    #+#             */
/*   Updated: 2024/05/02 11:52:31 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// collection of functions to print various things specific to program

#include "../../include/philos.h"

void	print_inputs(t_inputs inputs)
{
	if (VERBOSE != 1)
		return ;
	printf("Number of Philosophers: %d\n", inputs.number_of_philosophers);
	printf("Time to Die: %d\n", inputs.time_to_die);
	printf("Time to Eat: %d\n", inputs.time_to_eat);
	printf("Time to Sleep: %d\n", inputs.time_to_sleep);
	printf("Number of Times Each Philosopher Must Eat: %d\n", \
							inputs.times_a_philo_must_eat);
}

void	print_philo_input_data(t_philo_inputs *philo_input)
{
	if (VERBOSE == 0)
		return ;
	printf("----- PHILO %d:\n", philo_input->phid);
	print_inputs(philo_input->inputs);
	printf("\n");
}
