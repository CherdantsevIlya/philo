/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkari <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 17:22:45 by pkari             #+#    #+#             */
/*   Updated: 2021/11/29 17:22:49 by pkari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

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
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = (str[i] - '0') + (nbr * 10);
		i++;
	}
	if (str[i] != '\0')
		nbr = 0;
	return (nbr * count);
}

int	parsing(t_data *data, int argc, char **argv)
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
	if (data->num_of_philo <= 0 || data->num_of_philo > 200)
		return (printf("Error: wrong num_of_philo\n"));
	if (data->time_to_die < 60)
		return (printf("Error: wrong time_to_die\n"));
	if (data->time_to_eat < 60)
		return (printf("Error: wrong time_to_eat\n"));
	if (data->time_to_sleep < 60)
		return (printf("Error: wrong time_to_sleep\n"));
	if (argc == 6 && data->num_of_must_eat <= 0)
		return (printf("Error: wrong num_of_must_eat\n"));
	data->count_eat = 0;
	data->death_flag = 0;
	data->start_time = 0;
	return (0);
}

int	init_semaphore(t_data *data)
{
	sem_unlink("/forks");
	data->forks = sem_open("/forks", O_CREAT, S_IRWXU, data->num_of_philo);
	if (data->forks == SEM_FAILED)
		return (printf("Error: invalid semaphore init (forks)\n"));
	sem_unlink("/print");
	data->print = sem_open("/print", O_CREAT, S_IRWXU, 1);
	if (data->print == SEM_FAILED)
		return (printf("Error: invalid semaphore init (print)\n"));
	sem_unlink("/death_flag");
	data->death_flag = sem_open("/death_flag", O_CREAT, S_IRWXU, 0);
	if (data->death_flag == SEM_FAILED)
		return (printf("Error: invalid semaphore init (death_flag)\n"));
	sem_unlink("/count_eat");
	data->count_eat = sem_open("/count_eat", O_CREAT, S_IRWXU, 0);
	if (data->count_eat == SEM_FAILED)
		return (printf("Error: invalid semaphore init (count_eat)\n"));
	return (0);
}

int	init_philo(t_data *data)
{
	int	i;

	i = 0;
	data->philo = NULL;
	data->philo = (t_philo *)malloc(sizeof(*(data->philo))
			* data->num_of_philo);
	if (!(data->philo))
		return (printf("Error: failed to allocate memory\n"));
	while (i < data->num_of_philo)
	{
		data->philo[i].name = i;
		data->philo[i].sem_name = ft_itoa(i + 1);
		if (data->philo[i].sem_name == NULL)
			return (printf("Error: failed to allocate memory\n"));
		sem_unlink((const char *)data->philo[i].sem_name);
		data->philo[i].death = sem_open((const char *)data->philo[i].sem_name,
				O_CREAT, S_IRWXU, 1);
		if (data->philo[i].death == SEM_FAILED)
			return (printf("Error: invalid semaphore init\n"));
		data->philo[i].data = data;
		data->philo[i].num_of_eat = 0;
		data->philo[i].start_eat_time = 0;
		i++;
	}
	return (init_semaphore(data));
}
