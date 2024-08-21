/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 19:45:37 by likong            #+#    #+#             */
/*   Updated: 2024/08/19 13:10:19 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

size_t	str_len(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	putstr_fd(char *str, int fd)
{
	if (str == NULL)
	{
		if (putstr_fd("(null)", fd) == -1)
			return (-1);
		return (0);
	}
	if (write(fd, str, str_len(str)) == -1)
		return (-1);
	return (0);
}

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
