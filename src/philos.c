/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 08:40:53 by fschuber          #+#    #+#             */
/*   Updated: 2024/01/16 09:52:33 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// main

#include "../philos.h"

#include <stdio.h> // for printf
#include <stdlib.h> // for free

// number_of_philosophers time_to_die time_to_eat time_to_sleep
// [number_of_times_each_philosopher_must_eat]
int	main(int argc, char **argv)
{
	t_inputs		inputs;
	unsigned long	program_start_time;
	int				death_flag;
	pthread_t		*threads;
	int				counter;

	if (manage_input(argc, argv, &inputs) == -1)
		return (logger('e', "Input parameters invalid!"), -1);
	print_inputs(inputs);
	program_start_time = get_ms_timestamp();
	death_flag = 0;
	if (VERBOSE)
		printf("Program start time: %lu\n", program_start_time);
	threads = setup_philos(&inputs, program_start_time, &death_flag);
	if (!threads)
		return (-1);
	counter = -1;
	while (++counter < inputs.number_of_philosophers)
		pthread_join(threads[counter], NULL);
	free (threads);
	return (0);
}
