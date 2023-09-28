/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maouzal <maouzal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 23:35:27 by maouzal           #+#    #+#             */
/*   Updated: 2023/09/28 21:10:56 by maouzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    take_forks(t_data *data, t_philo *philo)
{
	int left_fork;
	int right_fork;
	
	left_fork = philo->id;
	right_fork = (philo->id + 1) % data->nb_philo;
	pthread_mutex_lock(&data->forks[left_fork]);
	printf("%d has taken a fork\n", philo->id);
	pthread_mutex_lock(&data->forks[right_fork]);
	printf("%d has taken a fork\n", philo->id);
}

void    eat(t_data *data, t_philo *philo)
{
	if (data->nb_eat == 0)
		return ;
	pthread_mutex_lock(&data->print);
	printf("%d is eating\n", philo->id);
	pthread_mutex_unlock(&data->print);
	usleep(data->time_to_eat * 1000);
	data->nb_eat--;
	pthread_mutex_unlock(&data->forks[philo->id]);
	pthread_mutex_unlock(&data->forks[(philo->id + 1) % data->nb_philo]);
}

void    sleep_think(t_data *data, t_philo *philo)
{
	pthread_mutex_lock(&data->print);
	printf("%d is sleeping\n", philo->id);
	pthread_mutex_unlock(&data->print);
	usleep(data->time_to_sleep * 1000);
	pthread_mutex_lock(&data->print);
	printf("%d is thinking\n", philo->id);
	pthread_mutex_unlock(&data->print);
}

void    routine(t_data *data, t_philo *philo)
{
	while (1)
	{
		take_forks(data, philo);
		eat(data, philo);
		sleep_think(data, philo);
	}
}

void    creat_treads(t_data *data, t_philo *philo)
{
	int i;

	i = 0;
	while (i < data->nb_philo)
	{
		pthread_create(philo->philo, NULL, &routine, philo);
		i++;
		philo->id++;
	}
}
