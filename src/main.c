/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 08:40:53 by fschuber          #+#    #+#             */
/*   Updated: 2024/05/15 09:30:42 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// main

#include "../include/philos.h"

static void	check_input_validity(t_inputs *inputs, int argc, char **argv)
{
	int	ret_val;

	ret_val = manage_input(argc, argv, inputs);
	if (ret_val == -2)
		logger(inputs, 'e', "Incorrect number of input args!");
	else if (ret_val == -3)
		logger(inputs, 'e', "Number of philosophers must be at least 1!");
	else if (ret_val == -4)
		logger(inputs, 'e', "Time parameters must be positive integers!");
	else if (ret_val == -5)
		logger(inputs, 'e', "Times a philo must eat must be positive!");
	else if (ret_val != 0)
		logger(inputs, 'e', "Input parameters invalid!");
	if (ret_val == 0 && LOG_INPUTS == 1)
	{
		logger(inputs, 'l', "Input parameters are valid!");
		print_inputs(*inputs);
	}
	else if (ret_val != 0)
		exit(1);
}

// number_of_philosophers time_to_die time_to_eat time_to_sleep
// [number_of_times_each_philosopher_must_eat]
int	main(int argc, char **argv)
{
	t_inputs		inputs;
	int				death_flag;
	pthread_t		*threads;

	printf("aaaaaaaaaaaaaaah");
	check_input_validity(&inputs, argc, argv);
	inputs.program_start_time = get_ms_timestamp();
	death_flag = 0;
	printf("im about to setup philos fuck how is this so hard");
	threads = setup_philos(&inputs, &death_flag);
	if (!threads)
		return (cleanup(&inputs, NULL), -1);
	cleanup(&inputs, threads);
	return (0);
}
