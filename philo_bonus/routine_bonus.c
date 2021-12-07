/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkari <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 17:23:43 by pkari             #+#    #+#             */
/*   Updated: 2021/11/29 17:23:45 by pkari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*end_routine(void *thread)
{
	int		i;
	t_data	*data;

	i = 0;
	data = thread;
	sem_wait(data->death_flag);
	while (i < data->num_of_philo)
	{
		kill(data->philo[i].pid, SIGTERM);
		i++;
	}
	return (NULL);
}

void	*eat_routine(void *thread)
{
	int		i;
	t_data	*data;

	i = 0;
	data = thread;
	while (i < data->num_of_philo)
	{
		sem_wait(data->count_eat);
		i++;
	}
	sem_post(data->death_flag);
	return (NULL);
}

void	*death_routine(void *thread)
{
	t_philo	*philo;

	pthread_detach(thread);
	philo = thread;
	while (1)
	{
		sem_wait(philo->death);
		sem_wait(philo->data->print);
		if (now() - philo->start_eat_time >= philo->data->time_to_die)
		{
			printf("%lld\t%d\tdied\n", now() - philo->data->start_time,
				   philo->name + 1);
			sem_post(philo->data->death_flag);
			return (NULL);
		}
		sem_post(philo->data->print);
		sem_post(philo->death);
	}
	return (NULL);
}

void	start_routine(t_philo *philo)
{
	pthread_t	death;

	pthread_create(&death, NULL, death_routine, philo);
	philo->start_eat_time = now();
	if (((philo->name) % 2) != 0)
		usleep(philo->data->time_to_eat * 500);
	if (philo->data->num_of_philo != 1)
	{
		while (1)
		{
			philo_takes_forks(philo);
			philo_eating(philo);
			philo_sleeping(philo);
			philo_thinking(philo);
		}
	}
	else
	{
		sem_wait(philo->data->forks);
		printf("%lld\t%d\thas taken a fork\n", now() - philo->data->start_time,
			   philo->name + 1);
		usleep(philo->data->time_to_die * 1000);
	}
	exit(0);
}

int	processes(t_data *data)
{
	int	i;

	i = 0;
	data->start_time = now();
	while (i < data->num_of_philo)
	{
		data->philo[i].pid = fork();
		if (data->philo[i].pid < 0)
			return (printf("Error: invalid fork\n"));
		if (data->philo[i].pid == 0)
			start_routine(&data->philo[i]);
		i++;
	}
	return (0);
}
