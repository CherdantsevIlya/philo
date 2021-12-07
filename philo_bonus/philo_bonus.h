/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkari <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 17:26:24 by pkari             #+#    #+#             */
/*   Updated: 2021/11/29 17:26:26 by pkari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <stdio.h>
# include <semaphore.h>
# include <fcntl.h>
# include <signal.h>
# include <sys/time.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <string.h>

typedef struct s_philo	t_philo;
typedef struct s_data	t_data;

struct	s_philo
{
	t_data		*data;
	int			name;
	char		*sem_name;
	int			num_of_eat;
	long long	start_eat_time;
	sem_t		*death;
	pid_t		pid;
};

struct	s_data
{
	t_philo		*philo;
	int			num_of_philo;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			num_of_must_eat;
	sem_t		*forks;
	sem_t		*print;
	sem_t		*death_flag;
	sem_t		*count_eat;
	long long	start_time;
};

int			processes(t_data *data);
void		start_routine(t_philo *philo);
void		*death_routine(void *thread);
void		*eat_routine(void *thread);
void		*end_routine(void *thread);

int			init_philo(t_data *data);
int			init_semaphore(t_data *data);
int			parsing(t_data *data, int argc, char **argv);
int			ft_atoi(const char *str);

void		philo_takes_forks(t_philo *philo);
void		philo_eating(t_philo *philo);
void		philo_sleeping(t_philo *philo);
void		philo_thinking(t_philo *philo);

void		free_data(t_data *data, int n);
void		philo_time_to(int time);
long long	now(void);

char		*ft_itoa(int n);

#endif
