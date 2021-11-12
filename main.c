#include "philo.h"

void *eat_routine()
{

}

void *death_routine(void *thread)
{

}

void *start_routine(void *thread)
{
	t_philo *philo;

	philo = thread;
	if (philo->name % 2 != 0)
		usleep(500);
	while (!philo->data->death_flag)
	{
		philo_takes_forks(philo);
		philo_eating(philo);
		philo_sleeping(philo);
		philo_thinking(philo);
	}
	return (NULL);
}

void threads(t_data *data, int argc)
{
	int			i;
	pthread_t	thread;

	i = -1;
	data->start_time = now();
	while (i++ < data->num_of_philo)
	{
		pthread_create(&data->philo[i].th, NULL, start_routine, data->philo[i]);
		pthread_create(&thread, NULL, death_routine, data->philo[i]);
		pthread_detach(thread);
	}
	if (argc == 6)
	{
		pthread_create(&thread, NULL, eat_routine, NULL);
		pthread_detach(thread);
	}
	i = -1;
	while (i++ < data->num_of_philo)
		pthread_join(data->philo[i], NULL);
}

int main(int argc, char **argv)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return (printf("Error: failed to allocate memory\n"));
	if (parsing(data, argc, argv))
		free_data(data, 1);
	if (init_philo(data))
		free_data(data, 1);
	threads(data, argc);
	free_data(data, 0);
}
