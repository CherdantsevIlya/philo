#include "philo_bonus.h"

void	free_data(t_data *data, int n)
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
	if (n == 1)
		exit(1);
	else
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
