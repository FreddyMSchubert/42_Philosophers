/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 09:18:44 by fschuber          #+#    #+#             */
/*   Updated: 2024/05/15 10:49:03 by fschuber         ###   ########.fr       */
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

static t_philo_inputs	*setup_philo_inputs(t_inputs	*inputs)
{
	int					i;
	t_philo_inputs		*philo_inputs;

	philo_inputs = malloc(sizeof(t_philo_inputs) * \
							inputs->number_of_philos);
	if (!philo_inputs)
		return (printf("Philo input allocation failed!\n"), NULL);
	i = -1;
	while (++i < inputs->number_of_philos)
	{
		philo_inputs[i].phid = i;
		philo_inputs[i].inputs = *inputs;
		philo_inputs[i].expected_eat_time = 0;
	}
	return (philo_inputs);
}

static int	allocate_mutexes(t_inputs *inputs)
{
	int				i;

	i = -1;
	while (++i < inputs->number_of_philos)
		if (allocate_and_init_mutex(&inputs->fork_mutexes[i]) != 0)
			return (-1);
	if (allocate_and_init_mutex(&inputs->printing_mutex) != 0)
		return (-1);
	if (allocate_and_init_mutex(&inputs->death_flag_mutex) != 0)
		return (-1);
	return (0);
}

pthread_t	*setup_philos(t_inputs	*inputs)
{
	int					i;
	pthread_t			*threads;
	t_philo_inputs		*philo_inputs;

	inputs->forks = malloc(sizeof(bool) * inputs->number_of_philos);
	inputs->fork_mutexes = malloc(sizeof(pthread_mutex_t *) * \
									inputs->number_of_philos);
	threads = malloc(sizeof(pthread_t) * inputs->number_of_philos);
	if (!inputs->fork_mutexes || !threads || !inputs->forks)
		return (printf("Fork / thread Mallocation failed.\n"), NULL);
	i = -1;
	while (++i < inputs->number_of_philos)
		inputs->forks[i] = false;
	if (allocate_mutexes(inputs) != 0)
		return (printf("Mutex allocation failed.\n"), NULL);
	philo_inputs = setup_philo_inputs(inputs);
	if (!philo_inputs)
		return (printf("Philo input setup failed.\n"), NULL);
	i = -1;
	while (++i < inputs->number_of_philos)
		pthread_create(&threads[i], NULL, philo_loop, &philo_inputs[i]);
	inputs->philo_inputs = philo_inputs;
	return (threads);
}
