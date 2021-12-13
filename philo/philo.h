/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkari <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 16:54:19 by pkari             #+#    #+#             */
/*   Updated: 2021/11/19 16:54:27 by pkari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <stdio.h>
# include <sys/time.h>
# include <string.h>

typedef struct s_philo	t_philo;
typedef struct s_data	t_data;

struct	s_philo
{
	t_data			*data;
	int				name;
	int				num_of_eat;
	long long		start_eat_time;
	int				left_fork;
	int				right_fork;
	pthread_mutex_t	death_mutex;
};

struct	s_data
{
	pthread_t		*thread;
	pthread_t		*death;
	t_philo			*philo;
	int				num_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_of_must_eat;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_mutex;
	int				death_flag;
	int				count_eat;
	long long		start_time;
};

int			threads(t_data *data, int argc);
void		*start_routine(void *thread);
void		*death_routine(void *thread);
void		*eat_routine(void *thread);

int			init_philo(t_data *data);
int			init_mutex(t_data *data);
int			parsing(t_data *data, int argc, char **argv);
int			ft_atoi(const char *str);

void		philo_takes_forks(t_philo *philo);
void		philo_eating(t_philo *philo);
void		philo_sleeping(t_philo *philo);
void		philo_thinking(t_philo *philo);

int			free_data(t_data *data, int n);
void		philo_time_to(int time);
long long	now(void);
void		twenty_five_lines(t_data *data, pthread_t *thread, pthread_t
				*death, int argc);

#endif
