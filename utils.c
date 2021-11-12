#include "philo.h"

void free_data(t_data *data, int n)
{
	int i;

	i = -1;
	while (i++ < data->num_of_philo)
	{
		free(data->philo[i]);
		free(data->forks[i]);
		pthread_mutex_destroy(data->forks[i]);
		pthread_mutex_destroy(data->philo->death_mutex[i]);
	}
	pthread_mutex_destroy(data->print_mutex);
	free(data->philo);
	free(data->forks);
	free(data);
	if (n == 1)
		exit(1);
	else
		exit(0);
}

long long now(void)
{
	struct timeval time;

	gettimeofday(time, NULL);
	return ((time.tv_sec * 1000 + time.tv_usec / 1000);
}