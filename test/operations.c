/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maouzal <maouzal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 23:35:27 by maouzal           #+#    #+#             */
/*   Updated: 2023/10/04 03:04:56 by maouzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_forks(t_info *info)
{
	pthread_mutex_lock(&info->data->forks[info->left_fork]);
	pthread_mutex_lock(&info->data->print);
	printf("%ld %d has taken a fork\n", (ft_get_time() - info->data->start_time),
		info->id);
	pthread_mutex_unlock(&info->data->print);
	pthread_mutex_lock(&info->data->forks[info->right_fork]);
	pthread_mutex_lock(&info->data->print);
	printf("%ld %d has taken a fork\n", (ft_get_time() - info->data->start_time),
		info->id);
	pthread_mutex_unlock(&info->data->print);
}

void	eat(t_info *info)
{
	pthread_mutex_lock(&info->data->print);
	printf("%ld %d is eating\n", (ft_get_time() - info->data->start_time),
		info->id);
	pthread_mutex_unlock(&info->data->print);
	pthread_mutex_lock(&info->data->check);
	info->eat_count++;
	info->last_eat = ft_get_time();
	pthread_mutex_unlock(&info->data->check);
	ft_usleep(info->data->time_to_eat);
	pthread_mutex_unlock(&info->data->forks[info->left_fork]);
	pthread_mutex_unlock(&info->data->forks[info->right_fork]);
}

void	*routine(void *arg)
{
	t_info	*info;

	info = (t_info *)arg;
	while (1)
	{
		take_forks(arg);
		eat(arg);
		pthread_mutex_lock(&info->data->print);
		printf("%ld %d is sleeping\n", (ft_get_time() - info->data->start_time),
			info->id);
		pthread_mutex_unlock(&info->data->print);
		ft_usleep(info->data->time_to_sleep);
		pthread_mutex_lock(&info->data->print);
		printf("%ld %d is thinking\n", (ft_get_time() - info->data->start_time),
			info->id);
		pthread_mutex_unlock(&info->data->print);
	}
}

void	creat_treads(t_info *info)
{
	int	i;

	i = 0;
	info->data->start_time = ft_get_time();
	while (i < info->data->nb_philo)
	{
		info[i].id = i + 1;
		info[i].left_fork = i;
		info[i].right_fork = (i + 1) % info->data->nb_philo;
		pthread_create(info[i].data->philo + i, NULL, routine, info + i);
		usleep(50);
		i++;
	}
}
