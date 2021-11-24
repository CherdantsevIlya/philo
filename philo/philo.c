/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkari <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 16:51:12 by pkari             #+#    #+#             */
/*   Updated: 2021/11/19 16:51:25 by pkari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_takes_forks(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->forks[philo->left_fork]);
	pthread_mutex_lock(&philo->data->forks[philo->right_fork]);
	pthread_mutex_lock(&philo->data->print_mutex);
	if (!philo->data->death_flag)
		printf("%lld\t%d\thas taken a fork\n",
			   now() - philo->data->start_time, philo->name + 1);
	if (!philo->data->death_flag)
		printf("%lld\t%d\thas taken a fork\n",
			   now() - philo->data->start_time, philo->name + 1);
	pthread_mutex_unlock(&philo->data->print_mutex);
}

void	philo_eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->death_mutex);
	pthread_mutex_lock(&philo->data->print_mutex);
	philo->start_eat_time = now();
	if (!philo->data->death_flag)
		printf("%lld\t%d\tis eating\n", philo->start_eat_time
			- philo->data->start_time, philo->name + 1);
	pthread_mutex_unlock(&philo->data->print_mutex);
	philo->num_of_eat += 1;
	if ((philo->num_of_eat == philo->data->num_of_must_eat)
		&& (!philo->data->death_flag))
		philo->data->count_eat += 1;
	philo_time_to(philo->data->time_to_eat);
	pthread_mutex_unlock(&philo->data->forks[philo->left_fork]);
	pthread_mutex_unlock(&philo->data->forks[philo->right_fork]);
	pthread_mutex_unlock(&philo->death_mutex);
}

void	philo_sleeping(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->print_mutex);
	if (!philo->data->death_flag)
		printf("%lld\t%d\tis sleeping\n",
			   now() - philo->data->start_time, philo->name + 1);
	pthread_mutex_unlock(&philo->data->print_mutex);
	philo_time_to(philo->data->time_to_sleep);
}

void	philo_thinking(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->print_mutex);
	if (!philo->data->death_flag)
		printf("%lld\t%d\tis thinking\n",
			   now() - philo->data->start_time, philo->name + 1);
	pthread_mutex_unlock(&philo->data->print_mutex);
}
