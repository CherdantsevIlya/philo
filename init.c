#include "philo.h"

int	ft_atoi(const char *str)
{
	int			i;
	int			count;
	long int	nbr;

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

int init_forks(t_data *data)
{
	int i;

	i = 0;
	data->forks = (pthread_mutex_t **)malloc(sizeof(pthread_mutex_t *) *
			data->input->num_of_filo);
	if (!(data->forks))
		return (printf("Error memory allocation\n"));
	while (i < data->input->num_of_filo)
	{
		data->forks[i] = (pthread_mutex_t *)mallo(sizeof(pthread_mutex_t));
		if (!(data->forks[i]))
			return (printf("Error memory allocation\n"));
		if (pthread_mutex_init(data->forks[i], NULL) != 0)
			return (printf("Error mutex initialization\n"));
		i++;
	}
	return (OK);
}

int init_philos(t_data *data)
{
	int i;

	i = 0;
	data->philo = (t_philo *)malloc(sizeof(t_philo) * data->input->num_of_filo);
	data->thread = (pthread_t *)malloc(sizeof(pthread_t) \
					* data->input->num_of_filo);
	if (!(data->philo) || !(data->thread))
		return (printf("Error memory allocation\n"));
	while (i < data->input->num_of_filo)
	{
		data->philo[i].name = i;
		// some infos about philo
		data->philo[i].left_fork = data->forks[i];
		if (i == 0)
			data->philo[i].right_fork
					= data->forks[data->input->num_of_filo - 1];
		else
			data.philo[i].right_fork = data->forks[i - 1];
		i++;
	}
	return (OK);
}

int init(int argc, char **argv, t_data *data)
{
	data->input = (t_input *)malloc(sizeof(t_input));
	if (!(data->input))
		return (printf("Error memory allocation\n"));
	data->input->num_of_filo = ft_atoi(argv[1]);
	data->input->time_to_die = ft_atoi(argv[2]);
	data->input->time_to_eat = ft_atoi(argv[3]);
	data->input->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->input->num_of_meals = ft_atoi(argv[5]);
	else
		data->input->num_of_meals = -1;
	if (data->input->num_of_meals == 0)
		return (EXIT);
	if (init_philos(data) || init_forks(data))
		return (ERROR);
	return (OK);
}