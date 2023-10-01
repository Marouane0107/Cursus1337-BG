/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maouzal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 23:35:27 by maouzal           #+#    #+#             */
/*   Updated: 2023/09/30 22:58:20 by maouzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    take_forks(t_info *info)
{
	pthread_mutex_lock(&info->data->forks[info->left_fork]);
	printf("%ld %d has taken a fork\n", (ft_get_time() - info->data->start_time), info->id);
	pthread_mutex_lock(&info->data->forks[info->right_fork]);
	printf("%ld %d has taken a fork\n", (ft_get_time() - info->data->start_time), info->id);
}

void    eat(t_info *info)
{
	pthread_mutex_lock(&info->data->print);
	printf("%ld %d is eating\n", (ft_get_time() - info->data->start_time), info->id);
	pthread_mutex_unlock(&info->data->print);
	ft_usleep(info->data->time_to_eat);
	info->eat_count++;
	info->last_eat = ft_get_time();
	pthread_mutex_unlock(&info->data->forks[info->left_fork]);
	pthread_mutex_unlock(&info->data->forks[info->right_fork]);
}

void    sleep_think(t_info *info)
{
	pthread_mutex_lock(&info->data->print);
	printf("%ld %d is sleeping\n", (ft_get_time() - info->data->start_time), info->id);
	pthread_mutex_unlock(&info->data->print);
	ft_usleep(info->data->time_to_sleep);
	pthread_mutex_lock(&info->data->print);
	printf("%ld %d is thinking\n",(ft_get_time() - info->data->start_time) , info->id);
	pthread_mutex_unlock(&info->data->print);
}

void    *routine(void *arg)
{
	while (1)
	{
		take_forks(arg);
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
