/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 08:46:23 by fschuber          #+#    #+#             */
/*   Updated: 2024/05/15 11:05:29 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

static int	check_minus(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] < '0' || s[i] > '9')
			return (-1);
		i++;
	}
	return (0);
}

int	ft_atoi(const char *s)
{
	int		i;
	int		sign;
	int		value;

	i = 0;
	sign = 1;
	value = 0;
	if (check_minus((char *)s) != 0)
		return (-1);
	if (!ft_isdigit(s[i]))
	{
		if (s[i] == '-')
			sign = -sign;
		if (s[i] == '-' || s[i] == '+')
			i++;
		else
			return (-1);
	}
	while (ft_isdigit(s[i]))
	{
		if (ft_isdigit(s[i]))
			value = (value * 10) + s[i] - 48;
		i++;
	}
	return (value * sign);
}
