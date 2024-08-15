/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 18:13:51 by likong            #+#    #+#             */
/*   Updated: 2024/08/15 20:07:12 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"
# include <pthread.h>

static void	init_phi_fork(t_data *d, t_philo *philo, int i)
{
	if (i % 2 == 0)
	{
		if (i == 0)
			philo->l_fork = &d->mutexes->forks[d->arg.phi_amount - 1];
		else
			philo->l_fork = &d->mutexes->forks[i - 1];
		philo->r_fork = &d->mutexes->forks[i];
	}
	else
	{
		philo->l_fork = &d->mutexes->forks[i - 1];
		philo->r_fork = &d->mutexes->forks[i];
	}
}

static int	init_philo(t_data *d)
{
	int	i;
	
	d->philo = (t_philo *)malloc(d->arg.phi_amount * sizeof(t_philo));
	if (!d->philo)
		return (1);
	i = -1;
	while ((++i) < d->arg.phi_amount)
	{
		d->philo[i].seat = i;
		d->philo[i].eat_count = 0;
		d->philo[i].exiting = 0;
		d->philo[i].arg = d->arg;
		d->philo[i].last_eat.tv_sec = d->arg.start.tv_sec;
		d->philo[i].last_eat.tv_usec = d->arg.start.tv_usec;
		d->philo[i].state = THINK;
		d->philo[i].self = &d->mutexes->philos[i];
		init_phi_fork(d, &(d->philo[i]), i);
	}
	return (0);
}

static int	init_mutex(t_data *d, t_mutex **mutex)
{
	int	i;

	*mutex = (t_mutex *)malloc(d->arg.phi_amount * sizeof(t_mutex));
	if (!*mutex)
		return (1);
	i = -1;
	while ((++i) < d->arg.phi_amount)
	{
		if (pthread_mutex_init(&(*mutex)[i], NULL) == -1)
		{
			putstr_fd("Cannot initialize mutex\n", 2);
			delete_mutex(mutex, i);
			return (1);
		}
	}
	return (0);
}

//doubts with mutex
static int	init_mutexes(t_data *d)
{
	if (init_mutex(d, &d->mutexes->forks))
		return (1);
	if (init_mutex(d, &d->mutexes->philos))
	{
		delete_mutex(&d->mutexes->forks, d->arg.phi_amount);
		return (1);
	}
	return (0);
}

int	init_data(t_data *d)
{
	d->mutexes = (t_mutexes *)malloc(sizeof(t_mutexes));
	if (!d->mutexes)
		return (1);
	d->mutexes->forks = NULL;
	d->mutexes->forks = NULL;
	if (init_mutexes(d))
		return (1);
	if (init_philo(d))
		return (1);
	return (0);
}
