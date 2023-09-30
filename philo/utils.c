/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maouzal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 23:35:27 by maouzal           #+#    #+#             */
/*   Updated: 2023/09/30 02:13:09 by maouzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    take_forks(t_info *info)
{
	printf("left_fork = %d\n", info->left_fork);
	printf("right_fork = %d\n", info->right_fork);
	pthread_mutex_lock(&info->data->forks[info->left_fork]);
	printf("%d has taken a fork\n", info->id);
	pthread_mutex_lock(&info->data->forks[info->right_fork]);
	printf("%d has taken a fork\n", info->id);
}

void    eat(t_info *info)
{
	if (info->data->nb_eat == 0)
	{
	printf("%d has finished eating\n", info->data->nb_eat);

		return ;
	}
	pthread_mutex_lock(&info->data->print);
	printf("%d is eating\n", info->id);
	pthread_mutex_unlock(&info->data->print);
	usleep(info->data->time_to_eat * 1000);
	if (info->data->nb_eat != -1)
		info->data->nb_eat--;
	pthread_mutex_unlock(&info->data->forks[info->left_fork]);
	pthread_mutex_unlock(&info->data->forks[info->right_fork]);
}

void    sleep_think(t_info *info)
{
	
	pthread_mutex_lock(&info->data->print);
	printf("%d is sleeping\n", info->id);
	pthread_mutex_unlock(&info->data->print);
	usleep(info->data->time_to_sleep * 1000);
	pthread_mutex_lock(&info->data->print);
	printf("%d is thinking\n", info->id);
	pthread_mutex_unlock(&info->data->print);
}

void    *routine(void *arg)
{
	while (1)
	{
		take_forks(arg);
		//printf("%deat\n");
		eat(arg);
		sleep_think(arg);
	}
}

void    creat_treads(t_info *info)
{
	int i;

	i = 0;
	while (i < info->data->nb_philo)
	{
		pthread_mutex_init(&info->data->forks[i], NULL);
		i++;
	}
	i = 0;
	while (i < info->data->nb_philo)
	{
		info[i].id = i + 1;
		info[i].left_fork = i;
		info[i].right_fork = (i + 1) % info->data->nb_philo;
		pthread_create(info[i].data->philo + i, NULL, routine, info + i);
		i++;
	}
}
