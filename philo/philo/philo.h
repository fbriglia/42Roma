/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbriglia <fbriglia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 16:08:56 by fbriglia          #+#    #+#             */
/*   Updated: 2024/03/11 16:08:58 by fbriglia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h> 
# include <unistd.h>

# define TOOK_FORK "has taken a fork"
# define THINKING "is thinking"
# define SLEEPING "is sleeping"
# define EATING "is eating"
# define DIED "died"

typedef struct s_data
{
	long long		start_time;
	int				num_philo;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				time_must_eat;
	int				stop;
	pthread_mutex_t	print_lock;
}					t_data;

typedef struct s_philo
{
	int				id;
	int				fork_ids[2];
	int				meals_counter;
	int				full;
	long long		last_meal;
	t_data			*data;
	pthread_mutex_t	rw_mutex;
	pthread_mutex_t	*forks;
}					t_philo;

typedef struct s_send
{
	t_data			*data;
	t_philo			*philos;
}					t_send;

int					parse_args(t_data *data, int argc, char *argv[]);
int					print_msg(int id, char *act, t_data *data, int d);
int					ft_atoi(char *str);
long long			now_ts(void);
void				ftime_sleep(int ms);
void				init_philosophers(t_data *data, t_philo *philos,
						pthread_mutex_t *forks);
void				*routine(void *arguments);
void				philo_action(t_philo *philo);
void				lone_philo_actionion(t_philo *philo);
void				*t_checker(void *args);
void				wait_start(long long st);
void				destroy_mutexes(pthread_mutex_t *forks, t_philo *philos,
						int num_philo);

#endif
