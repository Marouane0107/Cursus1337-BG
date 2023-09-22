#ifndef PHILO_H

# define PHILO_H
# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>


typedef struct s_philo
{
	pthread_t *philo;
	pthread_mutex_t *forks;
	int	id;
	int	nb_philo;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	nb_eat;
	int	*forks_status;

}		t_philo;


#endif