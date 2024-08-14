/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 15:37:24 by likong            #+#    #+#             */
/*   Updated: 2024/08/14 20:41:27 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

// unistd: write, usleep
// stdio: printf
// stdlib: malloc, free
// pthread: for thread function
// sys/time: timeval
// string: memset
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <string.h>

# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct timeval	t_time;

typedef enum e_state
{
	EAT,
	SLEEP,
	THINK
}	t_state;

typedef struct s_arg
{
	int		phi_amount;
	int		t_to_die;
	int		t_to_eat;
	int		t_to_sleep;
	int		eat_count;
	t_time	start;
}	t_arg;

typedef struct s_philo
{
	int		eat_count;
	t_time	last_eat;
}	t_philo;

typedef struct s_data
{
	t_arg	arg;
	t_philo	*philo;
	t_state	state;
}	t_data;

//atoi
int	ft_atoi(char *str);

//Tool functions
int		putstr_fd(char *str, int fd);
size_t	str_len(char *str);
int		show_error(t_data *test, char *str);

//Init part
int	init_data(t_data *d);

#endif
