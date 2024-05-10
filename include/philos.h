/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 08:50:34 by fschuber          #+#    #+#             */
/*   Updated: 2024/05/10 09:54:51 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// --- INCLUDES
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>  // threads, duh
#include <sys/time.h> // gettimeofday
#include <stdbool.h>  // bool type

#include "./colors.h" // ANSI color codes collection

#define VERBOSE 1
#define COLORFULOUTPUT 1
#define DETAILEDMESSAGES 1

// --- STRUCTS

// program command line inputs
typedef struct s_inputs
{
	int					number_of_philosophers;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					times_a_philo_must_eat;
	unsigned long		program_start_time;
	pthread_mutex_t		**forks;
	pthread_mutex_t		*printing_mutex;
}				t_inputs;

// data the philo threads get as input
typedef struct s_philo_inputs
{
	int					phid;
	int					*death_flag;
	t_inputs			inputs;
	unsigned long		expected_eat_time;
}				t_philo_inputs;

// --- INPUT

int				manage_input(int argc, char **argv, t_inputs	*inputs);

// --- SETUP

pthread_t		*setup_philos(t_inputs	*inputs, int *death_flag);

// --- PHILO ACTIONS

void			*philo_loop(void *arg);

int				determine_first_philo_to_eat(t_philo_inputs *philo_inputs);

int				philo_eat(t_philo_inputs *philo_inputs, \
							unsigned long *last_meal_time, int *times_eaten);
int				philo_think(t_philo_inputs *philo_inputs, \
							unsigned long last_meal_time);
int				philo_sleep(t_philo_inputs *philo_inputs, \
							unsigned long last_meal_time);

// --- CLEANUP

void			cleanup_mutexes(t_inputs *inputs);

// --- UTILS

int				ft_atoi(const char *s);
//  PRINTING
void			print_inputs(t_inputs inputs);
void			print_philo_input_data(t_philo_inputs *philo_input);
void			logger(t_inputs *inputs, char type, char *message);
void			log_philo_action(t_philo_inputs *in, char *msg);
void			log_detailed_philo_action(t_philo_inputs *in, char *msg);
// TIME
unsigned long	get_ms_timestamp(void);
void			ft_sleep(unsigned long ms);
int				get_eat_start_softness(t_philo_inputs *philo_inputs);
