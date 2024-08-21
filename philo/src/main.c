/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 15:37:28 by likong            #+#    #+#             */
/*   Updated: 2024/08/21 15:35:24 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static int	ft_free(t_data *d)
{
	delete_mutexes(d);
	if (d->mutexes)
		free(d->mutexes);
	if (d->philo)
		free(d->philo);
	free(d);
	return (1);
}

static void	init_arg(t_data *d, int i, int num)
{
	if (i == 1)
		d->arg.phi_amount = num;
	else if (i == 2)
		d->arg.t_to_die = num;
	else if (i == 3)
		d->arg.t_to_eat = num;
	else if (i == 4)
		d->arg.t_to_sleep = num;
	else if (i == 5)
		d->arg.eat_count = num;
	else
		d->arg.eat_count = 0;
}

static int	check_input_save(t_data *d, int argc, char **argv)
{
	int			i;
	int			res;
	static char	*num[6] = {"0", "1", "2", "3", "4", "5"};

	if (argc != 5 && argc != 6)
	{
		putstr_fd("Invalid number of argument\n", 2);
		return (1);
	}
	i = 0;
	while (argv[++i])
	{
		res = ft_atoi(argv[i]);
		if (res <= 0)
		{
			putstr_fd("Argument ", 2);
			putstr_fd(num[i], 2);
			putstr_fd(" is invalid\n", 2);
			return (1);
		}
		init_arg(d, i, res);
	}
	if (gettimeofday(&(d->arg.start), NULL) == -1)
		return (1);
	return (0);
}

//one more: 1 philo will die directly
int	main(int argc, char **argv)
{
	t_data	*d;

	d = (t_data *)malloc(sizeof(t_data));
	if (!d)
		return (1);
	memset(d, 0, sizeof(t_data));
	if (check_input_save(d, argc, argv))
	{
		free(d);
		return (1);
	}
	if (init_data(&d))
		return (ft_free(d));
	if (init_thread(d))
		return (ft_free(d));
	ft_free(d);
	return (0);
}
