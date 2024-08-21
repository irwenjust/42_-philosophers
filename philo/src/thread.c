/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 14:09:53 by likong            #+#    #+#             */
/*   Updated: 2024/08/21 12:19:20 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "../include/philo.h"

static void	loop_thread(t_philo *philo)
{
	while (!check_exit(philo))
	{
		if (take_fork(philo) == -1)
			break ;
		if (eat(philo) == -1)
			break ;
		if (ft_sleep(philo) == -1)
			break ;
		think(philo);
	}
}

static void	*new_thread(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *) arg;
	if (philo->seat % 2 == 0)
	{
		think(philo);
		real_sleep(philo, philo->arg.t_to_eat / 2);
	}
	loop_thread(philo);
	return (NULL);
}

int	init_thread(t_data *d)
{
	pthread_t	*th;
	int			i;

	th = (pthread_t *)malloc(d->arg.phi_amount * sizeof(pthread_t));
	if (!th)
		return (1);
	i = -1;
	while ((++i) < d->arg.phi_amount)
	{
		if (pthread_create(&th[i], NULL, &new_thread, &d->philo[i]) == -1)
		{
			putstr_fd("Create thread failed\n", 2);
			set_allexiting(d, th, i);
			free(th);
			return (1);
		}
	}
	start_listen(d, th);
	free(th);
	return (0);
}
