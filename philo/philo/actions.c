/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbriglia <fbriglia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 16:00:02 by fbriglia          #+#    #+#             */
/*   Updated: 2024/03/11 16:03:12 by fbriglia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_action(t_philo *philo)
{
	pthread_mutex_lock(&philo->forks[philo->fork_ids[0]]);
	print_msg(philo->id, TOOK_FORK, philo->data, philo->data->stop);
	pthread_mutex_lock(&philo->forks[philo->fork_ids[1]]);
	print_msg(philo->id, TOOK_FORK, philo->data, philo->data->stop);
	print_msg(philo->id, EATING, philo->data, philo->data->stop);
	pthread_mutex_lock(&philo->rw_mutex);
	philo->last_meal = now_ts();
	philo->meals_counter++;
	if (philo->meals_counter == philo->data->time_must_eat)
		philo->full = 1;
	pthread_mutex_unlock(&philo->rw_mutex);
	ftime_sleep(philo->data->time_eat);
	pthread_mutex_unlock(&philo->forks[philo->fork_ids[0]]);
	pthread_mutex_unlock(&philo->forks[philo->fork_ids[1]]);
	print_msg(philo->id, SLEEPING, philo->data, philo->data->stop);
	ftime_sleep(philo->data->time_sleep);
}

void	lone_philo_actionion(t_philo *philo)
{
	pthread_mutex_lock(&philo->forks[philo->fork_ids[0]]);
	print_msg(philo->id, TOOK_FORK, philo->data, philo->data->stop);
	ftime_sleep(philo->data->time_die);
}
