/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 08:40:53 by fschuber          #+#    #+#             */
/*   Updated: 2024/05/06 10:09:28 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// main

#include "../include/philos.h"

// number_of_philosophers time_to_die time_to_eat time_to_sleep
// [number_of_times_each_philosopher_must_eat]
int	main(int argc, char **argv)
{
	t_inputs		inputs;
	int				death_flag;
	pthread_t		*threads;
	int				counter;

	if (manage_input(argc, argv, &inputs) == -1)
		return (logger(&inputs, 'e', "Input parameters invalid!"), -1);
	print_inputs(inputs);
	inputs.program_start_time = get_ms_timestamp();
	death_flag = 0;
	if (VERBOSE)
		printf("Program start time: %lu\n", inputs.program_start_time);
	threads = setup_philos(&inputs, &death_flag);
	if (!threads)
		return (-1);
	counter = -1;
	while (++counter < inputs.number_of_philosophers)
		pthread_join(threads[counter], NULL);
	free (threads);
	cleanup_mutexes(&inputs);
	return (0);
}
