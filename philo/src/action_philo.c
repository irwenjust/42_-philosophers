/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 15:34:04 by likong            #+#    #+#             */
/*   Updated: 2024/08/21 12:20:09 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	real_sleep(t_philo *philo, long s_time)
{
	t_time	s_start;

	if (gettimeofday(&s_start, NULL) == -1)
		return (-1);
	while (passed_time(s_start) < s_time)
	{
		usleep(100);
		if (check_exit(philo))
		{
			if (philo->state == EAT)
				leave_forks(philo);
			return (-1);
		}
	}
	return (0);
}

int	eat(t_philo *philo)
{
	set_state(philo, EAT);
	set_ready_eat(philo);
	if (real_sleep(philo, philo->arg.t_to_eat) == -1)
		return (-1);
	leave_forks(philo);
	set_eat_count(philo);
	return (1);
}

int	ft_sleep(t_philo *philo)
{
	set_state(philo, SLEEP);
	if (real_sleep(philo, philo->arg.t_to_sleep) == -1)
		return (-1);
	return (0);
}

void	think(t_philo *philo)
{
	set_state(philo, THINK);
}
