/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 09:18:44 by fschuber          #+#    #+#             */
/*   Updated: 2024/01/11 10:19:15 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// setups mutexes and starts up philosopher threads

#include "../philos.h"

#include <stdlib.h>

int	setup_philos(t_inputs	*inputs)
{
	int					counter;
	pthread_mutex_t		*forks;
	pthread_t			*threads;
	t_philo_inputs		*philo_inputs;

	counter = -1;
	forks = malloc(sizeof(pthread_mutex_t) * inputs->number_of_philosophers);
	threads = malloc(sizeof(pthread_t) * inputs->number_of_philosophers);
	philo_inputs = malloc(sizeof(t_philo_inputs) * \
							inputs->number_of_philosophers);
	if (!forks || !threads || !philo_inputs)
		return (logger('e', "Fork Mallocation failed."), -1);
	while (++counter < inputs->number_of_philosophers)
		pthread_mutex_init(&forks[counter], NULL);
	logger('l', "Fork Mutexes initialized successfully.");
	counter = -1;
	while (++counter < inputs->number_of_philosophers)
	{
		philo_inputs[counter].phid = counter;
		philo_inputs[counter].inputs = *inputs;
		philo_inputs[counter].forks = forks;
		pthread_create(&threads[counter], NULL, philo_loop, \
											&philo_inputs[counter]);
	}
	return (0);
}
