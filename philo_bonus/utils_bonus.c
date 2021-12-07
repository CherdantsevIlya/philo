/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkari <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 17:25:07 by pkari             #+#    #+#             */
/*   Updated: 2021/11/29 17:25:09 by pkari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	free_data(t_data *data, int n)
{
	int	i;

	i = -1;
	if (data->philo)
	{
		while (++i < data->num_of_philo)
		{
			sem_close(data->philo[i].death);
			free(data->philo[i].sem_name);
		}
	}
	free(data->philo);
	sem_close(data->forks);
	sem_close(data->death_flag);
	sem_close(data->print);
	sem_close(data->count_eat);
	free(data);
	if (n == 1)
		exit(1);
	exit(0);
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
