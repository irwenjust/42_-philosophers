/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 19:45:37 by likong            #+#    #+#             */
/*   Updated: 2024/08/14 19:00:54 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	show_error(t_data *test, char *str)
{
	(void)test;
	printf("%s\n", str);
	return (1);
}

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
