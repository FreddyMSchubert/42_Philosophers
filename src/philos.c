/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 08:40:53 by fschuber          #+#    #+#             */
/*   Updated: 2024/01/09 09:29:55 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philos.h"

#include <stdio.h>

void	print_inputs(t_inputs inputs)
{
	printf("Number of Philosophers: %d\n", inputs.number_of_philosophers);
	printf("Time to Die: %d\n", inputs.time_to_die);
	printf("Time to Eat: %d\n", inputs.time_to_eat);
	printf("Time to Sleep: %d\n", inputs.time_to_sleep);
	printf("Number of Times Each Philosopher Must Eat: %d\n", \
							inputs.number_of_times_each_philosopher_must_eat);
}

// number_of_philosophers time_to_die time_to_eat time_to_sleep
// [number_of_times_each_philosopher_must_eat]
int	main(int argc, char **argv)
{
	t_inputs	inputs;

	if (manage_input(argc, argv, &inputs) == -1)
		logger('e', "Input parameters invalid!");
	print_inputs(inputs);
}
