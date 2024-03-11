/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbriglia <fbriglia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 16:00:57 by fbriglia          #+#    #+#             */
/*   Updated: 2024/03/11 18:22:47 by fbriglia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	print_msg(int id, char *act, t_data *data, int d)
{
	if (d)
		return (0);
	pthread_mutex_lock(&data->print_lock);
	printf("%lld %d %s\n", (now_ts() - data->start_time), id, act);
	pthread_mutex_unlock(&data->print_lock);
	return (0);
}

pthread_t	*start(t_data *data, t_philo *philos)
{
	int			i;
	pthread_t	*threads;

	i = 0;
	data->start_time = now_ts() + (data->num_philo * 2 * 10);
	threads = (pthread_t *)malloc (data->num_philo * sizeof(pthread_t));
	while (i < data->num_philo)
	{
		philos[i].last_meal = data->start_time;
		pthread_create(&threads[i], NULL, &routine, &philos[i]);
		i++;
	}
	return (threads);
}

int	_close(t_data *c, t_philo *p, pthread_t *t, char *msg)
{
	int	i;

	if (t)
		free(t);
	if (p)
		destroy_mutexes(p[0].forks, p, c->num_philo);
	if (c)
		free(c);
	if (msg)
	{
		i = -1;
		while (msg[++i])
			continue ;
		write(1, msg, i);
	}
	return (1);
}

void	start_t_checker(t_data *data, t_philo *philos, pthread_t *threads)
{
	int			i;
	pthread_t	t;
	t_send		send;

	i = -1;
	send.data = data;
	send.philos = philos;
	pthread_create(&t, NULL, &t_checker, &send);
	while (++i < data->num_philo)
		pthread_join(threads[i], NULL);
	i = -1;
	pthread_join(t, NULL);
}

int	main(int argc, char *argv[])
{
	t_data			*data;
	t_philo			*philos;
	pthread_mutex_t	*forks;
	pthread_t		*threads;

	if (argc <= 4 || argc >= 7)
		return (_close(NULL, NULL, NULL, "not enough args\n"));
	data = (t_data *)malloc (sizeof(t_data));
	if (!data)
		return (_close(NULL, NULL, NULL, "data error\n"));
	if (parse_args(data, argc, argv))
		return (_close(data, NULL, NULL, "args error\n"));
	philos = (t_philo *)malloc (data->num_philo * sizeof(t_philo));
	if (!philos)
		return (_close(data, NULL, NULL, "philo error\n"));
	forks = (pthread_mutex_t *)malloc (data->num_philo
			* sizeof(pthread_mutex_t));
	if (!forks)
		return (_close(data, NULL, NULL, "forks error\n"));
	init_philosophers(data, philos, forks);
	threads = start(data, philos);
	start_t_checker(data, philos, threads);
	return (_close(data, philos, threads, NULL));
}
