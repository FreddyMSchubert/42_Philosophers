/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 09:18:44 by fschuber          #+#    #+#             */
/*   Updated: 2024/01/16 09:53:10 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// setups mutexes and starts up philosopher threads

#include "../philos.h"

#include <stdlib.h> // for malloc
#include <stdio.h> // for printf

static t_philo_inputs	*setup_philo_inputs(t_inputs	*inputs, \
								unsigned long program_start_time, \
								int *death_flag, pthread_mutex_t *forks)
{
	int					counter;
	t_philo_inputs		*philo_inputs;

	philo_inputs = malloc(sizeof(t_philo_inputs) * \
							inputs->number_of_philosophers);
	if (!philo_inputs)
		return (printf("Philo input allocation failed!\n"), NULL);
	counter = -1;
	while (++counter < inputs->number_of_philosophers)
	{
		philo_inputs[counter].phid = counter;
		philo_inputs[counter].inputs = *inputs;
		philo_inputs[counter].forks = forks;
		philo_inputs[counter].program_start_time = program_start_time;
		philo_inputs[counter].death_flag = death_flag;
	}
	return (philo_inputs);
}

pthread_t	*setup_philos(t_inputs	*inputs, unsigned long program_start_time, \
							int *death_flag)
{
	int					counter;
	pthread_mutex_t		*forks;
	pthread_t			*threads;
	t_philo_inputs		*philo_inputs;

	counter = -1;
	forks = malloc(sizeof(pthread_mutex_t) * inputs->number_of_philosophers);
	threads = malloc(sizeof(pthread_t) * inputs->number_of_philosophers);
	if (!forks || !threads)
		return (printf("Fork mallocation failed.\n"), free(forks), \
									free(threads), NULL);
	counter = -1;
	while (++counter < inputs->number_of_philosophers)
		pthread_mutex_init(&forks[counter], NULL);
	philo_inputs = setup_philo_inputs(inputs, program_start_time, \
												death_flag, forks);
	if (!philo_inputs)
		return (printf("Philo input setup failed.\n"), free(forks), \
								free(threads), NULL);
	counter = -1;
	while (++counter < inputs->number_of_philosophers)
		pthread_create(&threads[counter], NULL, philo_loop, \
													&philo_inputs[counter]);
	return (threads);
}
