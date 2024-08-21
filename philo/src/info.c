/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 16:18:12 by likong            #+#    #+#             */
/*   Updated: 2024/08/21 12:19:49 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

t_time	get_eat_time(t_philo *philo)
{
	t_time	res;

	pthread_mutex_lock(philo->self);
	res = philo->last_eat;
	pthread_mutex_unlock(philo->self);
	return (res);
}

int	get_count(t_philo *philo)
{
	int	res;

	pthread_mutex_lock(philo->self);
	res = philo->eat_count;
	pthread_mutex_unlock(philo->self);
	return (res);
}

long	passed_time(t_time start)
{
	t_time	curr;
	long	ms;

	if (gettimeofday(&curr, NULL) == -1)
		return (-1);
	ms = (curr.tv_sec - start.tv_sec) * 1000
		+ (curr.tv_usec - start.tv_usec) / 1000;
	return (ms);
}

int	check_exit(t_philo *philo)
{
	int	res;

	pthread_mutex_lock(philo->self);
	res = philo->exiting;
	pthread_mutex_unlock(philo->self);
	return (res);
}
