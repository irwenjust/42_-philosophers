/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_philo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 18:02:51 by likong            #+#    #+#             */
/*   Updated: 2024/08/21 12:20:38 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	print_info(t_philo *philo)
{
	long	ms;
	char	*str;

	if (check_exit(philo))
		return ;
	pthread_mutex_lock(philo->self);
	ms = passed_time(philo->arg.start);
	if (philo->state == EAT)
		str = "is eating";
	else if (philo->state == SLEEP)
		str = "is sleeping";
	else if (philo->state == THINK)
		str = "is thinking";
	else
		str = "";
	printf("%ld %d %s\n", ms, philo->seat + 1, str);
	pthread_mutex_unlock(philo->self);
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
	philo->state = state;
	print_info(philo);
}
