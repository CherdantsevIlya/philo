#include "philo.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	count;
	int	nbr;

	i = 0;
	count = 1;
	nbr = 0;
	while (str[i] == '\n' || str[i] == '\r' || str[i] == '\t'
		   || str[i] == '\v' || str[i] == '\f' || str[i] == ' ')
		i++;
	if (str[i] == '-')
		count = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9' && str[i] != '\0')
	{
		nbr = (str[i] - '0') + (nbr * 10);
		i++;
	}
	return (nbr * count);
}

int parsing(t_data *data, int argc, char **argv)
{
	if (argc != 5 && argc != 6)
		return (printf("Error: wrong num of args\n"));
	data->num_of_philo = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->num_of_must_eat = ft_atoi(argv[5]);
	else
		data->num_of_must_eat = -1;
	if (data->num_of_philo <= 0)
		return (printf("Error: wrong num_of_philo\n"));
	if (data->time_to_die <= 0)
		return (printf("Error: wrong time_to_die\n"));
	if (data->time_to_eat <= 0)
		return (printf("Error: wrong time_to_eat\n"));
	if (data->time_to_sleep <= 0)
		return (printf("Error: wrong time_to_sleep\n"));
	if (argc == 6 && data->num_of_must_eat <= 0)
		return (printf("Error: wrong num_of_must_eat\n"));
	return (0);
}

int init_philo(t_data *data)
{
	int i;

	i = 0;
	data->count_eat = 0;
	data->death_flag = 0;
	data->philo = (t_philo *)malloc(sizeof(t_philo) * data->num_of_philo);
	data->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) *
											data->num_of_philo);
	if (!(data->philo) || !(data->forks))
		return (printf("Error: failed to allocate memory\n"));
	pthread_mutex_init(&data->print_mutex, NULL);
	while (i < data->num_of_philo)
	{
		pthread_mutex_init(data->philo[i].death_mutex, NULL);
		pthread_mutex_init(&data->forks[i], NULL);
		data->philo[i].name = i;
		data->philo[i].data = data;
		data->philo[i]->num_of_eat = 0;
		data->philo[i].left_fork = data->forks[i];
		if (i == 0)
			data->philo[i].right_fork = data->forks[data->num_of_philo - 1];
		else
			data->philo[i].right_fork = data->forks[i - 1];
		i++;
	}
	return (0);
}
