#ifndef PHILO_H

# define PHILO_H
# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_philo
{
	pthread_t *philo;
	int	id;

}		t_philo;

typedef struct s_data
{
	pthread_mutex_t *forks;
	pthread_mutex_t	print;
	int	nb_philo;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	nb_eat;

}		t_data;

int		ft_atoi(char *str);
void    take_forks(t_data *data, t_philo *philo);
void    eat(t_data *data, t_philo *philo);
void    sleep_think(t_data *data, t_philo *philo);
void    routine(t_data *data, t_philo *philo);
void    creat_treads(t_data *data, t_philo *philo);

#endif