/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 08:45:33 by fschuber          #+#    #+#             */
/*   Updated: 2024/05/06 10:09:18 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philos.h"

void	cleanup_mutexes(t_inputs *inputs)
{
	int		counter;

	if (VERBOSE)
		printf("Cleaning up mutexes\n");
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
}
