/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maouzal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 17:35:05 by maouzal           #+#    #+#             */
/*   Updated: 2023/10/02 02:48:14 by maouzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int ft_atoi(char *str)
{
	int i;
	int res;

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
	struct timeval time;
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
		usleep(100);
	return (0);
}

void	*check_death(t_info *info)
{
	while (1)
	{
		pthread_mutex_lock(&info->data->check);
		if (info->data->finish_eat == info->data->nb_eat)
			return (NULL);
		if (ft_get_time() - info->last_eat > info->data->time_to_die)
		{
			pthread_mutex_unlock(&info->data->check);
			pthread_mutex_lock(&info->data->print);
			printf("%ld %d died\n", (ft_get_time() - info->data->start_time), info->id);
			return (NULL);
		}
		pthread_mutex_unlock(&info->data->check);
	}
}
