/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbriglia <fbriglia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 15:57:20 by fbriglia          #+#    #+#             */
/*   Updated: 2024/03/11 16:09:20 by fbriglia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	destroy_mutexes(pthread_mutex_t *forks, t_philo *philos, int num_philo)
{
	int	i;

	i = -1;
	while (++i < num_philo)
	{
		pthread_mutex_destroy(&forks[i]);
		pthread_mutex_destroy(&philos[i].rw_mutex);
	}
	free(forks);
	free(philos);
}

int	control_philos(t_philo *philos, t_data *data)
{
	int	i;
	int	r;

	i = -1;
	r = 1;
	while (++i < data->num_philo)
	{
		if (data->stop)
			break ;
		pthread_mutex_lock(&philos[i].rw_mutex);
		if (now_ts() - philos[i].last_meal > data->time_die)
		{
			print_msg(i + 1, DIED, data, data->stop);
			data->stop = 1;
		}
		if (!philos[i].full)
			r = 0;
		pthread_mutex_unlock(&philos[i].rw_mutex);
	}
	if (r)
		return (r);
	return (data->stop);
}

void	*t_checker(void *args)
{
	t_send	*send;

	send = (t_send *)args;
	wait_start(send->data->start_time);
	while (1)
	{
		if (control_philos(send->philos, send->data))
			break ;
		usleep(1000);
	}
	return (0);
}

void	*routine(void *args)
{
	t_philo			*philo;
	unsigned long	start;

	philo = (t_philo *)args;
	start = philo->data->start_time;
	wait_start(start);
	if (!(philo->id % 2))
		ftime_sleep(200);
	if (philo->data->num_philo == 1)
	{
		print_msg(philo->id, THINKING, philo->data, philo->data->stop);
		lone_philo_actionion(philo);
		return (NULL);
	}
	while (!philo->data->stop)
	{
		print_msg(philo->id, THINKING, philo->data, philo->data->stop);
		philo_action(philo);
		if (philo->full)
			break ;
	}
	return (NULL);
}

void	init_philosophers(t_data *data, t_philo *philos, pthread_mutex_t *forks)
{
	int	i;

	i = 0;
	while (i++ < data->num_philo)
	{
		pthread_mutex_init(&forks[i], NULL);
		pthread_mutex_init(&philos[i].rw_mutex, NULL);
		philos[i].forks = forks;
		philos[i].id = i + 1;
		philos[i].meals_counter = 0;
		philos[i].full = 0;
		philos[i].data = data;
		philos[i].fork_ids[0] = i;
		philos[i].fork_ids[1] = (i + 1) % data->num_philo;
	}
}
