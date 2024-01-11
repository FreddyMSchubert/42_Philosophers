/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 08:50:34 by fschuber          #+#    #+#             */
/*   Updated: 2024/01/11 10:15:40 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define VERBOSE 1

// --- INCLUDES
#include <pthread.h>

// --- STRUCTS

// program command line inputs
typedef struct s_inputs
{
	int		number_of_philosophers;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		number_of_times_each_philosopher_must_eat;
}				t_inputs;

// data the philo threads get as input
typedef struct s_philo_inputs
{
	int					phid;
	t_inputs			inputs;
	pthread_mutex_t		*forks;
}				t_philo_inputs;

// --- IMPORTANT STUFF

int			setup_philos(t_inputs	*inputs);
void		*philo_loop(void *arg);

// --- UTILS

void		logger(char type, char *message);
int			ft_atoi(const char *s);

// --- INPUT

int			manage_input(int argc, char **argv, t_inputs	*inputs);

// --- PRINTING

void		print_inputs(t_inputs inputs);
void		print_philo_input_data(t_philo_inputs *philo_input);