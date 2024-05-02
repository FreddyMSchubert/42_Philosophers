/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logger.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 08:48:57 by fschuber          #+#    #+#             */
/*   Updated: 2024/05/02 10:47:35 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philos.h"

/*
	@brief		Logs a message with a type in front and a new line in the end.
				Types: e - Error, l - Logger, s - Success;
*/
void	logger(char type, char *message)
{
	if (VERBOSE == 0)
		return ;
	if (type == 'e')
		printf("%sERROR%s: ", ANSI_COLOR_RED, ANSI_COLOR_RESET);
	if (type == 'l')
		printf("%sLOGGER%s: ", ANSI_COLOR_YELLOW, ANSI_COLOR_RESET);
	if (type == 's')
		printf("%sSUCCESS%s: ", ANSI_COLOR_GREEN, ANSI_COLOR_RESET);
	printf("%s\n", message);
}

void	log_philo_action(unsigned long time, int phid, char *message)
{
	int		philo_color;

	philo_color = (phid % 6) + 31;
	if (COLORFULOUTPUT == 1)
		printf("%lu\t\033[%dm%d %s\033[0m\n", time, philo_color, phid, message);
	else
		printf("%lu %d %s\n", time, phid, message);
}
