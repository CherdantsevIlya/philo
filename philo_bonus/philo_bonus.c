#include "philo_bonus.h"

void	philo_takes_forks(t_philo *philo)
{
	sem_wait(philo->data->forks);
	sem_wait(philo->data->forks);
	sem_wait(philo->data->print)
	if (!philo->data->death_flag)
		printf("%lld\t%d\thas taken a fork\n",
			   now() - philo->data->start_time, philo->name + 1);
	if (!philo->data->death_flag)
		printf("%lld\t%d\thas taken a fork\n",
			   now() - philo->data->start_time, philo->name + 1);
	sem_post(philo->data->print);
}

void	philo_eating(t_philo *philo)
{
	sem_wait(philo->death);
	sem_wait(philo->data->print)
	philo->start_eat_time = now();
	if (!philo->data->death_flag)
		printf("%lld\t%d\tis eating\n", philo->start_eat_time
			- philo->data->start_time, philo->name + 1);
	sem_post(philo->data->print);
	philo->num_of_eat += 1;
	if (philo->num_of_eat == philo->data->num_of_must_eat)
		sem_post(philo->data->count_eat);
	philo_time_to(philo->data->time_to_eat);
	sem_post(philo->data->forks);
	sem_post(philo->data->forks);
	sem_post(philo->death);
}

void	philo_sleeping(t_philo *philo)
{
	sem_wait(philo->data->print)
	if (!philo->data->death_flag)
		printf("%lld\t%d\tis sleeping\n",
			   now() - philo->data->start_time, philo->name + 1);
	sem_post(philo->data->print);
	philo_time_to(philo->data->time_to_sleep);
}

void	philo_thinking(t_philo *philo)
{
	sem_wait(philo->data->print)
	if (!philo->data->death_flag)
		printf("%lld\t%d\tis thinking\n",
			   now() - philo->data->start_time, philo->name + 1);
	sem_post(philo->data->print);
}
