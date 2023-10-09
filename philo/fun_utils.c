/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maouzal <maouzal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 17:35:05 by maouzal           #+#    #+#             */
/*   Updated: 2023/10/04 02:57:31 by maouzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(char *str)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	if (str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] > '9' || str[i] < '0')
			return (-1);
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (res);
}

long	ft_get_time(void)
{
	struct timeval	time;
	long			res;

	gettimeofday(&time, NULL);
	res = ((time.tv_sec * 1000) + (time.tv_usec / 1000));
	return (res);
}

int	ft_usleep(int time)
{
	long	start;

	start = ft_get_time();
	while (ft_get_time() - start < time)
		usleep(50);
	return (0);
}

int	eat_check(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->data->nb_philo && info->data->nb_eat != -1)
	{
		if (info[i].eat_count >= info->data->nb_eat)
			i++;
		else
			break ;
	}
	if (i == info->data->nb_philo)
	{
		pthread_mutex_lock(&info->data->print);
		printf("All philosophers have eaten %d times\n", info->data->nb_eat);
		pthread_mutex_unlock(&info->data->check);
		return (1);
	}
	return (0);
}

void	*check_death(t_info *info)
{
	int	i;

	i = 0;
	while (1)
	{
		if (i == info->data->nb_philo - 1)
			i = 0;
		if (info[i].last_eat == 0)
			info[i].last_eat = ft_get_time();
		pthread_mutex_lock(&info->data->check);
		if (eat_check(info))
			return (NULL);
		if (ft_get_time() - info[i].last_eat > info->data->time_to_die)
		{
			pthread_mutex_lock(&info->data->print);
			printf("%ld %d has died \n",
				(ft_get_time() - info->data->start_time), info->id);
			pthread_mutex_unlock(&info->data->check);
			return (NULL);
		}
		i++;
		pthread_mutex_unlock(&info->data->check);
	}
}
