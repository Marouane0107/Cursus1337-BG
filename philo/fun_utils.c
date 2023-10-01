/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maouzal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 17:35:05 by maouzal           #+#    #+#             */
/*   Updated: 2023/10/01 00:25:48 by maouzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int ft_atoi(char *str)
{
	int i;
	int res;

	i = 0;
	res = 0;
	if (str[i] == '-')
		return (-1);
	if (str[i] == '+')
		i++;
	while (str[i])
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (res);
}

int	ft_get_time(void)
{
	struct timeval time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

int	ft_usleep(int time)
{
	int start;

	start = ft_get_time();
	while (ft_get_time() - start < time)
		usleep(20);
	return (0);
}

void	*check_death(t_info *info)
{
	while (1)
	{
		if (info->data->nb_eat == 0 || info->eat_count == info->data->nb_eat)
			return (NULL);
		if (ft_get_time() - info->last_eat > info->data->time_to_die)
		{
			pthread_mutex_lock(&info->data->print);
			printf("%d died\n", info->id);
			pthread_mutex_unlock(&info->data->print);
			return (NULL);
		}
	}
}
