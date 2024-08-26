/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_philo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 18:02:51 by likong            #+#    #+#             */
/*   Updated: 2024/08/26 11:09:06 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	print_info(t_philo *philo, char *info)
{
	long	ms;
	char	*str;

	if (check_exit(philo))
		return ;
	pthread_mutex_lock(philo->printer);
	ms = passed_time(philo->arg.start);
	if (info)
		str = info;
	else if (philo->state == SLEEP)
		str = "is sleeping";
	else if (philo->state == THINK)
		str = "is thinking";
	else if (philo->state == EAT)
		str = "is eating";
	else
		str = "\n";
	printf("%ld %d %s\n", ms, philo->seat + 1, str);
	pthread_mutex_unlock(philo->printer);
}

int	set_exiting(t_philo *philo)
{
	pthread_mutex_lock(philo->self);
	philo->exiting = 1;
	pthread_mutex_unlock(philo->self);
	return (1);
}

void	set_eat_count(t_philo *philo)
{
	pthread_mutex_lock(philo->self);
	philo->eat_count++;
	pthread_mutex_unlock(philo->self);
}

int	set_ready_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->self);
	if (gettimeofday(&philo->last_eat, NULL) == -1)
	{
		pthread_mutex_unlock(philo->self);
		return (-1);
	}
	pthread_mutex_unlock(philo->self);
	return (0);
}

void	set_state(t_philo *philo, t_state state)
{
	pthread_mutex_lock(philo->self);
	philo->state = state;
	pthread_mutex_unlock(philo->self);
	print_info(philo, NULL);
}
