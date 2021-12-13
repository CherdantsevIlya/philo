/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkari <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 16:32:12 by pkari             #+#    #+#             */
/*   Updated: 2021/11/19 16:32:47 by pkari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*eat_routine(void *thread)
{
	t_data	*data;

	data = thread;
	while (!data->death_flag)
	{
		pthread_mutex_lock(&data->print_mutex);
		if (data->count_eat == data->num_of_philo)
			data->death_flag = 1;
		pthread_mutex_unlock(&data->print_mutex);
	}
	return (NULL);
}

void	*death_routine(void *thread)
{
	t_philo	*philo;

	philo = thread;
	while (!philo->data->death_flag)
	{
		pthread_mutex_lock(&philo->death_mutex);
		pthread_mutex_lock(&philo->data->print_mutex);
		if (now() - philo->start_eat_time >= philo->data->time_to_die
			&& !philo->data->death_flag)
		{
			printf("%lld\t%d\tdied\n", now() - philo->data->start_time,
				   philo->name + 1);
			philo->data->death_flag = 1;
		}
		pthread_mutex_unlock(&philo->data->print_mutex);
		pthread_mutex_unlock(&philo->death_mutex);
	}
	return (NULL);
}

void	*start_routine(void *thread)
{
	t_philo	*philo;

	philo = thread;
	philo->start_eat_time = now();
	if (((philo->name) % 2) != 0)
		usleep(philo->data->time_to_eat * 500);
	if (philo->data->num_of_philo != 1)
	{
		while (!philo->data->death_flag)
		{
			philo_takes_forks(philo);
			philo_eating(philo);
			philo_sleeping(philo);
			philo_thinking(philo);
		}
	}
	else
	{
		pthread_mutex_lock(&philo->data->forks[philo->left_fork]);
		if (!philo->data->death_flag)
			printf("%lld\t%d\thas taken a fork\n",
				   now() - philo->data->start_time, philo->name + 1);
		usleep(philo->data->time_to_die * 1000);
	}
	return (NULL);
}

int	threads(t_data *data, int argc)
{
	int			i;
	pthread_t	*thread;
	pthread_t	*death;

	i = -1;
	thread = (pthread_t *)malloc(sizeof(pthread_t) * data->num_of_philo);
	death = (pthread_t *)malloc(sizeof(pthread_t) * data->num_of_philo);
	if (!thread || !death)
		return (printf("Error: failed to allocate memory\n"));
	data->start_time = now();
	while (++i < data->num_of_philo)
		pthread_create(&thread[i], NULL, start_routine, &data->philo[i]);
	usleep(1000);
	i = -1;
	while (++i < data->num_of_philo)
		pthread_create(&death[i], NULL, death_routine, &data->philo[i]);
	twenty_five_lines(data, thread, death, argc);
	free(thread);
	free(death);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return (printf("Error: failed to allocate memory\n"));
	if (parsing(data, argc, argv))
	{
		free(data);
		return (1);
	}
	if (init_philo(data))
		return (free_data(data, 1));
	if (threads(data, argc))
		return (free_data(data, 1));
	usleep(data->time_to_eat * 1000);
	return (free_data(data, 0));
}
