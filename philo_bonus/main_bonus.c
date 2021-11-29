/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkari <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 17:20:55 by pkari             #+#    #+#             */
/*   Updated: 2021/11/29 17:20:59 by pkari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	main(int argc, char **argv)
{
	t_data		*data;
	pthread_t	eat;
	pthread_t	end;

	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return (printf("Error: failed to allocate memory\n"));
	if (parsing(data, argc, argv))
	{
		free(data);
		return (1);
	}
	if (init_philo(data))
		free_data(data, 0, 1);
	if (processes(data))
		free_data(data, 1, 1);
	if (argc == 6)
		pthread_create(&eat, NULL, eat_routine, data);
	pthread_create(&end, NULL, end_routine, data);
	free_data(data, 1, 0);
}
