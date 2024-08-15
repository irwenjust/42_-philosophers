/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 09:23:23 by likong            #+#    #+#             */
/*   Updated: 2024/08/15 12:37:48 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	delete_mutex(t_mutex **mutex, int count)
{
	int	i;

	i = -1;
	if (*mutex == NULL)
		return ;
	while ((++i) < count)
		pthread_mutex_destroy((&(*mutex)[i]));
	free(*mutex);
}

void	delete_mutexes(t_data *d)
{
	delete_mutex(&d->mutexes->forks, d->arg.phi_amount);
	delete_mutex(&d->mutexes->philos, d->arg.phi_amount);
}
