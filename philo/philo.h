/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maouzal <maouzal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 20:58:06 by maouzal           #+#    #+#             */
/*   Updated: 2023/10/04 03:02:29 by maouzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H

# define PHILO_H
# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct s_data
{
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
	pthread_mutex_t	check;
	pthread_t		*philo;
	int				id;
	int				nb_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_eat;
	long			start_time;
}		t_data;

typedef struct s_info
{
	int		id;
	int		left_fork;
	int		right_fork;
	long	last_eat;
	int		eat_count;
	t_data	*data;
}		t_info;

int		ft_atoi(char *str);
long	ft_get_time(void);
int		ft_usleep(int time);
void	take_forks(t_info *info);
void	eat(t_info *info);
void	sleep_think(t_info *data);
void	*routine(void *arg);
void	creat_treads(t_info *info);
void	*check_death(t_info *info);

#endif