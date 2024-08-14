/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 18:13:51 by likong            #+#    #+#             */
/*   Updated: 2024/08/14 20:21:05 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static int	init_philo(t_data *d)
{
	int	i;
	
	d->philo = (t_philo *)malloc(d->arg.phi_amount * sizeof(t_philo));
	if (!d->philo)
		return (1);
	i = -1;
	while ((++i) < d->arg.phi_amount)
	{
		d->philo[i].eat_count = 0;
		d->philo[i].last_eat.tv_sec = d->arg.start.tv_sec;
		d->philo[i].last_eat.tv_usec = d->arg.start.tv_usec;
	}
	return (0);
}

int	init_data(t_data *d)
{
	if (init_philo(d))
		return (1);
	return (0);
}
