/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 15:37:24 by likong            #+#    #+#             */
/*   Updated: 2024/08/21 12:23:13 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

// unistd: write, usleep
// stdio: printf
// stdlib: malloc, free
// pthread: for thread function
// sys/time: timeval
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct timeval	t_time;
typedef pthread_mutex_t	t_mutex;

typedef enum e_state
{
	EAT,
	SLEEP,
	THINK
}	t_state;

typedef struct s_mutexes
{
	t_mutex	*forks;
	t_mutex	*philos;
}	t_mutexes;

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
	int		seat;
	int		eat_count;
	int		exiting;
	t_arg	arg;
	t_time	last_eat;
	t_state	state;
	t_mutex	*self;
	t_mutex	*l_fork;
	t_mutex	*r_fork;
}	t_philo;

typedef struct s_data
{
	t_arg		arg;
	t_philo		*philo;
	t_mutexes	*mutexes;
}	t_data;

//atoi
int		ft_atoi(char *str);

//Tool functions
int		putstr_fd(char *str, int fd);
size_t	str_len(char *str);

//Init part
int		init_data(t_data **d);

//Delete part
void	delete_mutexes(t_data *d);
void	delete_mutex(t_mutex **mutex, int count);

//Thread part
int		init_thread(t_data *d);

//Info part
int		check_exit(t_philo *philo);
long	passed_time(t_time start);
int		get_count(t_philo *philo);
t_time	get_eat_time(t_philo *philo);

//Philo action
void	think(t_philo *philo);
int		ft_sleep(t_philo *philo);
int		real_sleep(t_philo *philo, long s_time);
int		eat(t_philo *philo);

//Fork action
int		take_fork(t_philo *philo);
void	leave_forks(t_philo *philo);

//Set philo
void	set_state(t_philo *philo, t_state state);
int		set_ready_eat(t_philo *philo);
void	set_eat_count(t_philo *philo);
int		set_exiting(t_philo *philo);

//Listener
void	start_listen(t_data *d, pthread_t *th);
void	set_allexiting(t_data *d, pthread_t *th, int count);

#endif
