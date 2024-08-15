/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listener.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 19:05:56 by likong            #+#    #+#             */
/*   Updated: 2024/08/15 20:37:14 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	set_allexiting(t_data *d, pthread_t *th, int count)
{
	int	i;

	i = -1;
	while ((++i) < count)
		set_exiting(&d->philo[i]);
	i = -1;
	while ((++i) < count)
		pthread_join(th[i], NULL);
}

//> or >= 
static int	check_dead(t_philo *philo)
{
	t_time	start;

	start = get_eat_time(philo);
	if (passed_time(start) > philo->arg.t_to_die)
		return (0);
	return (1);
}

static int	one_dead(t_data *d, pthread_t *th)
{
	int	i;

	i = -1;
	while ((++i) < d->arg.phi_amount)
	{
		if (check_dead(&d->philo[i]) == 0)
		{
			printf("%ld %d died\n", passed_time(d->arg.start), i + 1);
			set_allexiting(d, th, d->arg.phi_amount);
			return (0);
		}
	}
	return (-1);
}

static int	all_done(t_data *d, pthread_t *th)
{
	int	i;

	i = -1;
	while ((++i) < d->arg.phi_amount)
	{
		if (get_count(&d->philo[i]) < d->arg.eat_count)
			return (-1);
	}
	set_allexiting(d, th, d->arg.phi_amount);
	return (0);
}

void	start_listen(t_data *d, pthread_t *th)
{
	while (1)
	{
		usleep(200);
		if (d->arg.eat_count != 0)
		{
			if (all_done(d, th) == 0)
				break;
		}
		if (one_dead(d, th) == 0)
			break;
	}
}
