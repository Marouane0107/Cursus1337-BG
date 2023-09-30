/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maouzal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 17:29:50 by maouzal           #+#    #+#             */
/*   Updated: 2023/09/30 01:49:44 by maouzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

int	init_philo(t_data *data, t_info *info, int argc, char **argv)
{
	info->id = 1;
	data->time_to_die = ft_atoi(argv[2]);
	if (data->time_to_die < 60)
		return (printf("Error, time too short !"), 1);
	data->time_to_eat = ft_atoi(argv[3]);
	if (data->time_to_eat < 60)
		return (printf("Error, time too short !"), 1);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (data->time_to_sleep < 60)
		return (printf("Error, time too short !"), 1);
	if (argc == 6)
		data->nb_eat = ft_atoi(argv[5]);
	else
		data->nb_eat = -1;
	return (0);
}


int main(int argc, char **argv)
{
	t_data *data;
	t_info *info;
	int i;
	
	i = 0;
	if (argc < 5 || argc > 6)
		return (0);
	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return (0);
	data->nb_philo = ft_atoi(argv[1]);
	if (data->nb_philo < 2)
		return (printf("Error, time too short !"), 0);
	info = (t_info *)malloc(sizeof(t_info) * data->nb_philo);
	if (!info)
		return (0);
	data->forks = malloc(sizeof(pthread_mutex_t) * data->nb_philo);
	if (!data->forks)
		return (0);
	data->philo = malloc(sizeof(pthread_t) * data->nb_philo);
	if (!data->philo)
		return (0);
	if (init_philo(data, info, argc, argv))
		return (0);
	while (i < data->nb_philo)
		info[i++].data = data;
	
	pthread_mutex_init(&data->print, NULL);
	creat_treads(info);
	pthread_mutex_destroy(data->forks);
	pthread_mutex_destroy(&data->print);
	return (0);
}
