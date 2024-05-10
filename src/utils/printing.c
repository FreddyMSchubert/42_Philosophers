/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 09:11:07 by fschuber          #+#    #+#             */
/*   Updated: 2024/05/10 09:48:32 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// collection of functions to print various things specific to program

#include "../../include/philos.h"

// prints before threading, thus no need for mutex
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

/*
	@brief		Logs a msg with a type in front and a new line in the end.
				Types: e - Error, l - Logger, s - Success;

				if the printing mutex is not set up, it will not be used.
*/
void	logger(t_inputs *inputs, char type, char *msg)
{
	if (VERBOSE != 1)
		return ;
	if (inputs->printing_mutex)
		pthread_mutex_lock(inputs->printing_mutex);
	if (type == 'e')
		printf("%sERROR%s: ", ANSI_COLOR_RED, ANSI_COLOR_RESET);
	if (type == 'l')
		printf("%sLOGGER%s: ", ANSI_COLOR_YELLOW, ANSI_COLOR_RESET);
	if (type == 's')
		printf("%sSUCCESS%s: ", ANSI_COLOR_GREEN, ANSI_COLOR_RESET);
	printf("%s\n", msg);
	if (inputs->printing_mutex)
		pthread_mutex_unlock(inputs->printing_mutex);
}

void	log_philo_action(t_philo_inputs *in, char *msg)
{
	int				philo_color;
	unsigned long	time;

	time = get_ms_timestamp() - in->inputs.program_start_time;
	philo_color = (in->phid % 6) + 31;
	pthread_mutex_lock(in->inputs.printing_mutex);
	if (COLORFULOUTPUT == 1)
		printf("%lu\t\033[%dm%d %s\033[0m\n", time, philo_color, in->phid, msg);
	else
		printf("%lu %d %s\n", time, in->phid, msg);
	pthread_mutex_unlock(in->inputs.printing_mutex);
}

void	log_detailed_philo_action(t_philo_inputs *in, char *msg)
{
	if (DETAILEDMESSAGES == 0)
		return ;
	log_philo_action(in, msg);
}
