/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 17:23:57 by likong            #+#    #+#             */
/*   Updated: 2024/08/14 19:09:53 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static int	is_space_or_not(char c)
{
	return (c == ' ' || c == '\t'
		|| c == '\n' || c == '\r'
		|| c == '\v' || c == '\f');
}

static int	check_sign(char c, int sig)
{
	if (c == '-')
		sig = (-1) * sig;
	return (sig);
}

//only work for 64 bytes system
int	ft_atoi(char *str)
{
	int	i;
	int	sig;
	int	num;
	int	check;

	i = 0;
	num = 0;
	sig = 1;
	while (is_space_or_not(str[i]))
		i++;
	if ((str[i] == '+' || str[i] == '-') && str[i + 1] != '\0')
		sig = check_sign(str[i++], sig);
	while (str[i] >= '0' && str[i] <= '9')
	{
		check = num * 10 + str[i++] - '0';
		if (check / 10 != num && sig == 1)
			return (-1);
		if (check / 10 != num && sig == -1)
			return (0);
		num = check;
	}
	if (str[i] != '\0')
		return (-1);
	return (sig * num);
}
