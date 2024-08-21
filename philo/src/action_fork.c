/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_fork.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 16:29:45 by likong            #+#    #+#             */
/*   Updated: 2024/08/21 11:36:14 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	print_fork(t_philo philo)
{
	long	ms;

	ms = passed_time(philo.arg.start);
	if (!check_exit(&philo))
		printf("%ld %d %s\n", ms, philo.seat + 1, "has taken a fork");
}

void	leave_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
}

//maybe change sleep
int	wait_die(t_philo philo)
{
	real_sleep(&philo, philo.arg.t_to_die * 2);
	pthread_mutex_unlock(philo.r_fork);
	return (-1);
}

int	take_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->r_fork);
	if (check_exit(philo))
	{
		pthread_mutex_unlock(philo->r_fork);
		return (-1);
	}
	print_fork(*philo);
	if (philo->arg.phi_amount == 1)
		return (wait_die(*philo));
	pthread_mutex_lock(philo->l_fork);
	if (check_exit(philo))
	{
		leave_forks(philo);
		return (-1);
	}
	print_fork(*philo);
	return (0);
}
