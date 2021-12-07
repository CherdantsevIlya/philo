/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkari <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 17:02:07 by pkari             #+#    #+#             */
/*   Updated: 2021/11/19 17:02:16 by pkari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	free_data(t_data *data, int n)
{
	int	i;

	if (data->forks)
	{
		i = 0;
		while (i < data->num_of_philo)
			pthread_mutex_destroy(&data->forks[i++]);
		free(data->forks);
	}
	if (data->philo)
	{
		i = 0;
		while (i < data->num_of_philo)
			pthread_mutex_destroy(&data->philo[i++].death_mutex);
		free(data->philo);
	}
	pthread_mutex_destroy(&data->print_mutex);
	free(data);
	return (n);
}

long long	now(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	philo_time_to(int time)
{
	long long	x;
	long long	y;

	x = now() + time;
	while (now() < x)
	{
		y = x - now();
		if (y <= 50)
			usleep(10);
		else
			usleep(100);
	}
}

void	twenty_five_lines(t_data *data)
{
	pthread_t	eat;

	pthread_create(&eat, NULL, eat_routine, data);
	pthread_detach(eat);
}
