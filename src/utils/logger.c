/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logger.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 08:48:57 by fschuber          #+#    #+#             */
/*   Updated: 2024/01/09 08:55:13 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philos.h"

#include <stdio.h> // for printf

/*
	@brief		Logs a message with a type in front and a new line in the end.
				Types: e - Error, l - Logger, s - Success;
*/
void	logger(char type, char *message)
{
	if (VERBOSE == 0)
		return ;
	if (type == 'e')
		printf("\033[31mERROR\033[0m: ");
	if (type == 'l')
		printf("\033[33mLOGGER\033[0m: ");
	if (type == 's')
		printf("\033[32mSUCCESS\033[0m: ");
	printf("%s\n", message);
}
