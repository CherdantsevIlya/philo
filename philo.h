#ifndef PHILO_H
#define PHILO_H

# define OK 0
# define ERROR 1
# define EXIT 1

#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>
#include <sys/time.h>
#include <string.h>

typedef struct s_input
{
	int num_of_filo;
	int time_to_die;
	int time_to_eat;
	int time_to_sleep;
	int num_of_meals;
} 	t_input;

typedef struct s_philo
{
	int name;
	pthread_mutex_t left_fork;
	pthread_mutex_t right_fork;
	pthread_mutex_t printf_mutex;
}	t_philo;

typedef struct s_data
{
	pthread_t		*thread;
	pthread_mutex_t	*forks;
	t_philo			*philo;
	t_input			*input;
}	t_data;

/*
 **		parsing.c
 */

void rules(void);
int is_num(char *str);
int parsing(int argc, char **argv);

/*
 **		parsing.c
 */

int init(int argc, char **argv, t_data *data);
int init_philos(t_data *data);
int init_forks(t_data *data);
int	ft_atoi(const char *str);

#endif
