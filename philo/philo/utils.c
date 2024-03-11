/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbriglia <fbriglia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 16:09:35 by fbriglia          #+#    #+#             */
/*   Updated: 2024/03/11 17:58:06 by fbriglia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(char *str)
{
	int	sign;
	int	r;
	int	i;

	r = 0;
	i = 0;
	sign = 1;
	if (!str)
		return (0);
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		r = r * 10 + (str[i] - '0');
		i++;
	}
	return (r * sign);
}

long long	now_ts(void)
{
	struct timeval	current_time;
	long long		t;

	gettimeofday(&current_time, NULL);
	t = (current_time.tv_sec) * 1000 + (current_time.tv_usec) / 1000;
	return (t);
}

void	wait_start(long long timestamp)
{
	while (now_ts() < timestamp)
		continue ;
}

int	parse_args(t_data *data, int argc, char *argv[])
{
	int	j;
	int	x;

	j = 0;
	while (++j < argc)
	{
		x = -1;
		while (argv[j][++x])
		{
			if (!(argv[j][x] >= '0' && argv[j][x] <= '9'))
				return (1);
		}
	}
	data->stop = 0;
	data->num_philo = ft_atoi(argv[1]);
	printf("num_philo= %d\n", data->num_philo);
	data->time_die = ft_atoi(argv[2]);
	data->time_eat = ft_atoi(argv[3]);
	data->time_sleep = ft_atoi(argv[4]);
	data->time_must_eat = -1;
	if (argc == 6)
		data->time_must_eat = ft_atoi(argv[5]);
	pthread_mutex_init(&(data->print_lock), NULL);
	return (0);
}

void	ftime_sleep(int ms)
{
	long long	f;

	f = now_ts() + ms;
	while (now_ts() < f)
		usleep(100);
}
