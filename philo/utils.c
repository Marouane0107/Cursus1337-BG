/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maouzal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 23:35:27 by maouzal           #+#    #+#             */
/*   Updated: 2023/09/22 20:45:30 by maouzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    take_forks(t_philo *data)
{
	int left_fork;
	int right_fork;
	
	left_fork = data->id;
	right_fork = (data->id + 1) % data->nb_philo;
	pthread_mutex_lock(&data->forks[left_fork]);
	pthread_mutex_lock(&data->forks[right_fork]);
	data->forks_status[left_fork] = 1;
	data->forks_status[right_fork] = 1;
}

void    eat(t_philo *data)
{
	if (data->nb_eat == 0)
		return ;
	printf("%d is eating\n", data->id);
	usleep(data->time_to_eat * 1000);
	data->nb_eat--;
}

void    sleep(t_philo *data)
{
	printf("%d is sleeping\n", data->id);
	usleep(data->time_to_sleep * 1000);
}

void    think(t_philo *data)
{
	printf("%d is thinking\n", data->id);
}

void    routine(t_philo *data)
{
	while (1)
	{
		take_forks(data);
		eat(data);
		sleep(data);
		think(data);
	}
}

void    creat_treads(t_philo *data)
{
	int i;

	i = 0;
	while (i < data->nb_philo)
	{
		pthread_create(data->philo, NULL, &routine, data);
		i++;
	}
	i = 0;
	while (i < data->nb_philo)
	{
		pthread_join(data->philo, NULL);
		i++;
	}
}
