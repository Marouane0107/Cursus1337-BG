/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maouzal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 17:29:50 by maouzal           #+#    #+#             */
/*   Updated: 2023/09/29 02:05:25 by maouzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

int	init_philo(t_data *data, t_philo *philo, int argc, char **argv)
{
	philo->id = 1;
	data->nb_philo = ft_atoi(argv[1]);
	if (data->nb_philo < 2)
		return (printf("Error, time too short !"), 1);
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
	t_philo *philo;

	if (argc < 5 || argc > 6)
		return (0);
	data = (t_data *)malloc(sizeof(t_data));
	philo = (t_philo *)malloc(sizeof(t_philo));
	if (!data || !philo)
		return (0);
	if (init_philo(data, philo, argc, argv))
		return (0);
	pthread_mutex_init(data->forks, NULL);
	creat_treads(data, philo);
	return (0);
}
