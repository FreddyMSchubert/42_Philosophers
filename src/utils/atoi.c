/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 08:46:23 by fschuber          #+#    #+#             */
/*   Updated: 2024/01/09 08:48:01 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_isspace(const char s)
{
	if (s == ' ' || s == '\t' || s == '\n' || s == '\v')
		return (1);
	if (s == '\f' || s == '\r')
		return (1);
	return (0);
}

static int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	ft_atoi(const char *s)
{
	int		i;
	int		sign;
	int		value;

	i = 0;
	sign = 1;
	value = 0;
	while (ft_isspace(s[i]))
		i++;
	if (!ft_isdigit(s[i]))
	{
		if (s[i] == '-')
			sign = -sign;
		if (s[i] == '-' || s[i] == '+')
			i++;
		else
			return (0);
	}
	while (ft_isdigit(s[i]))
	{
		if (ft_isdigit(s[i]))
			value = (value * 10) + s[i] - 48;
		i++;
	}
	return (value * sign);
}
