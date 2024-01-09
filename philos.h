/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 08:50:34 by fschuber          #+#    #+#             */
/*   Updated: 2024/01/09 09:24:46 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define VERBOSE 1

// --- STRUCTS

typedef struct s_inputs
{
	int		number_of_philosophers;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		number_of_times_each_philosopher_must_eat;
}				t_inputs;

// --- UTILS

void		logger(char type, char *message);
int			ft_atoi(const char *s);

// --- INPUT

int			manage_input(int argc, char **argv, t_inputs	*inputs);