/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 09:48:13 by fschuber          #+#    #+#             */
/*   Updated: 2024/01/11 10:11:32 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philos.h"

void	*philo_loop(void *arg)
{
	t_philo_inputs	*philo_inputs;

	philo_inputs = (t_philo_inputs *)arg;
	print_philo_input_data(philo_inputs);
	return (0);
}
