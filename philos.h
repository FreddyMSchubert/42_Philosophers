/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: freddy <freddy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 08:50:34 by fschuber          #+#    #+#             */
/*   Updated: 2024/01/15 12:34:55 by freddy           ###   ########.fr       */
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
	unsigned long		program_start_time;
	t_inputs			inputs;
	pthread_mutex_t		*forks;
}				t_philo_inputs;

// --- IMPORTANT STUFF

pthread_t		*setup_philos(t_inputs	*inputs, unsigned long program_start_time);

// --- PHILO ACTIONS

void			*philo_loop(void *arg);
int				philo_eat(t_philo_inputs *philo_inputs, unsigned long *last_meal_time, int *times_eaten);
int				philo_think(t_philo_inputs *philo_inputs);
int				philo_sleep(t_philo_inputs *philo_inputs);

// --- UTILS

void			logger(char type, char *message);
int				ft_atoi(const char *s);

// --- INPUT

int				manage_input(int argc, char **argv, t_inputs	*inputs);

// --- PRINTING

void			print_inputs(t_inputs inputs);
void			print_philo_input_data(t_philo_inputs *philo_input);

// --- TIME

unsigned long	get_ms_timestamp(void);