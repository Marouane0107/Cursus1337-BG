/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maouzal <maouzal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 17:29:50 by maouzal           #+#    #+#             */
/*   Updated: 2023/09/28 20:40:10 by maouzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"



int main(int argc, char **argv)
{
	t_data *data;
	t_philo *philo;

	if (argc < 5 || argc > 6)
		return (0);
	philo = (t_philo *)malloc(sizeof(t_philo));
	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return (0);
	philo->id = 1;
	data->nb_philo = ft_atoi(argv[1]);
	if (data->nb_philo < 2)
		return (0);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->nb_eat = ft_atoi(argv[5]);
	else
		data->nb_eat = -1;
	pthread_mutex_init(philo->philo, NULL);
	creat_treads(philo->philo);
	return (0);
}
