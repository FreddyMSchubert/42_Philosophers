/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 08:45:33 by fschuber          #+#    #+#             */
/*   Updated: 2024/05/15 10:46:59 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philos.h"

static void	cleanup_threads(pthread_t *threads, int number_of_philos)
{
	int		counter;

	counter = -1;
	while (++counter < number_of_philos)
		pthread_join(threads[counter], NULL);
	free(threads);
}

static void	cleanup_mutexes(t_inputs *inputs)
{
	int		counter;

	counter = -1;
	while (++counter < inputs->number_of_philos)
	{
		if (inputs->fork_mutexes[counter])
		{
			pthread_mutex_destroy(inputs->fork_mutexes[counter]);
			free(inputs->fork_mutexes[counter]);
		}
	}
	free(inputs->fork_mutexes);
	free(inputs->forks);
	if (inputs->printing_mutex)
	{
		pthread_mutex_destroy(inputs->printing_mutex);
		free(inputs->printing_mutex);
	}
	if (inputs->death_flag_mutex)
	{
		pthread_mutex_destroy(inputs->death_flag_mutex);
		free(inputs->death_flag_mutex);
	}
}

void	cleanup(t_inputs *inputs, pthread_t *threads)
{
	if (threads)
		cleanup_threads(threads, inputs->number_of_philos);
	if (inputs->philo_inputs)
		free(inputs->philo_inputs);
	cleanup_mutexes(inputs);
}
