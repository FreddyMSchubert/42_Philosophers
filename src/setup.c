/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 09:18:44 by fschuber          #+#    #+#             */
/*   Updated: 2024/05/10 11:30:36 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// setups mutexes and starts up philosopher threads

#include "../include/philos.h"

static int	allocate_and_init_mutex(pthread_mutex_t **mutex_ptr)
{
	*mutex_ptr = malloc(sizeof(pthread_mutex_t));
	if (*mutex_ptr == NULL)
	{
		fprintf(stderr, "Failed to allocate memory for mutex.\n");
		return (-1);
	}
	if (pthread_mutex_init(*mutex_ptr, NULL) != 0)
	{
		fprintf(stderr, "Failed to initialize mutex.\n");
		free(*mutex_ptr);
		*mutex_ptr = NULL;
		return (-1);
	}
	return (0);
}

static t_philo_inputs	*setup_philo_inputs(t_inputs	*inputs, \
								int *death_flag)
{
	int					i;
	t_philo_inputs		*philo_inputs;

	philo_inputs = malloc(sizeof(t_philo_inputs) * \
							inputs->number_of_philosophers);
	if (!philo_inputs)
		return (printf("Philo input allocation failed!\n"), NULL);
	i = -1;
	while (++i < inputs->number_of_philosophers)
	{
		philo_inputs[i].phid = i;
		philo_inputs[i].inputs = *inputs;
		philo_inputs[i].death_flag = death_flag;
		philo_inputs[i].expected_eat_time = 0;
	}
	return (philo_inputs);
}

pthread_t	*setup_philos(t_inputs	*inputs, int *death_flag)
{
	int					i;
	pthread_mutex_t		**forks;
	pthread_t			*threads;
	t_philo_inputs		*philo_inputs;

	i = -1;
	forks = malloc(sizeof(pthread_mutex_t *) * inputs->number_of_philosophers);
	threads = malloc(sizeof(pthread_t) * inputs->number_of_philosophers);
	if (!forks || !threads)
		return (printf("Fork mallocation failed.\n"), NULL);
	i = -1;
	while (++i < inputs->number_of_philosophers)
		if (allocate_and_init_mutex(&forks[i]) != 0)
			return (printf("Mutex allocation failed.\n"), NULL);
	if (allocate_and_init_mutex(&inputs->printing_mutex) != 0)
		return (printf("Printing mutex allocation failed.\n"), NULL);
	inputs->forks = forks;
	philo_inputs = setup_philo_inputs(inputs, death_flag);
	if (!philo_inputs)
		return (printf("Philo input setup failed.\n"), NULL);
	i = -1;
	while (++i < inputs->number_of_philosophers)
		pthread_create(&threads[i], NULL, philo_loop, &philo_inputs[i]);
	inputs->philo_inputs = philo_inputs;
	return (threads);
}
