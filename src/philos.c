/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: freddy <freddy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 08:40:53 by fschuber          #+#    #+#             */
/*   Updated: 2024/01/15 12:33:16 by freddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// main

#include "../philos.h"

#include <stdio.h>

#include <unistd.h> // for usleep, temp delete me

// number_of_philosophers time_to_die time_to_eat time_to_sleep
// [number_of_times_each_philosopher_must_eat]
int	main(int argc, char **argv)
{
	t_inputs		inputs;
	unsigned long	program_start_time;
	pthread_t		*threads;

	if (manage_input(argc, argv, &inputs) == -1)
	{
		logger('e', "Input parameters invalid!");
		return (-1);
	}
	print_inputs(inputs);
	program_start_time = get_ms_timestamp();
	printf("Program start time: %lu\n", program_start_time);
	threads = setup_philos(&inputs, program_start_time);
	if (!threads)
		return (-1);
	for (int i = 0; i < inputs.number_of_philosophers; i++)
		pthread_join(threads[i], NULL);
	return (0);
}
