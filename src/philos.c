/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 08:40:53 by fschuber          #+#    #+#             */
/*   Updated: 2024/01/11 10:18:26 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// main

#include "../philos.h"

#include <stdio.h>

// number_of_philosophers time_to_die time_to_eat time_to_sleep
// [number_of_times_each_philosopher_must_eat]
int	main(int argc, char **argv)
{
	t_inputs	inputs;

	if (manage_input(argc, argv, &inputs) == -1)
	{
		logger('e', "Input parameters invalid!");
		return (-1);
	}
	print_inputs(inputs);
	setup_philos(&inputs);
}
