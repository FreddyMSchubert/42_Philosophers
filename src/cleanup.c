/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 08:45:33 by fschuber          #+#    #+#             */
/*   Updated: 2024/05/10 11:41:48 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philos.h"

static void	cleanup_threads(pthread_t *threads, int number_of_philosophers)
{
	int		counter;

	counter = -1;
	while (++counter < number_of_philosophers)
		pthread_join(threads[counter], NULL);
	free(threads);
}

void	cleanup(t_inputs *inputs, pthread_t *threads)
{
	int		counter;

	if (threads)
		cleanup_threads(threads, inputs->number_of_philosophers);
	counter = -1;
	while (++counter < inputs->number_of_philosophers && inputs->forks != NULL)
	{
		if (inputs->forks[counter])
		{
			pthread_mutex_destroy(inputs->forks[counter]);
			free(inputs->forks[counter]);
		}
	}
	free(inputs->forks);
	if (inputs->printing_mutex)
	{
		pthread_mutex_destroy(inputs->printing_mutex);
		free(inputs->printing_mutex);
	}
	if (inputs->philo_inputs)
		free(inputs->philo_inputs);
}
