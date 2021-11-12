#ifndef PHILO_H
#define PHILO_H

#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>
#include <sys/time.h>
#include <string.h>

typedef struct s_philo t_philo;
typedef struct s_data t_data;

struct	s_philo
{
	t_data			*data;
	int 			name;
	int 			num_of_eat;
	long long		start_eat_time;
	pthread_t		th;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t *death_mutex;
};

struct	s_data
{
	t_philo			*philo;
	int 			num_of_philo;
	int 			time_to_die;
	int 			time_to_eat;
	int 			time_to_sleep;
	int				num_of_must_eat;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_mutex;
	int 			death_flag;
	int 			count_eat;
	long long		start_time;
};

void threads(t_data *data, int argc);
void *start_routine(void *thread);
void *death_routine(void *thread);
void *eat_routine();

int init_philo(t_data *data);
int parsing(t_data *data, int argc, char **argv);
int	ft_atoi(const char *str);

void philo_takes_forks(t_philo *philo)
void philo_eating(t_philo *philo);
void philo_sleeping(t_philo *philo);
void philo_thinking(t_philo *philo);

void free_data(t_data *data, int n);
long long now(void);

#endif
