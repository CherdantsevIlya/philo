#include "philo.h"

int start_treads(t_data *data)
{
	int i;

	i = 0;
	while (i < data->input->num_of_filo)
	{
		if (i % 2 == 0)
			if (pthread_create(&data->philo[i]->th, NULL, start_routine,
					  data->philo[i]) != 0)
				return (printf("Error thread create\n"));
		i++;
	}
	sleep(5);
	i = 0;
	while (i < data->input->num_of_filo)
	{
		if (i % 2 != 0)
			if (pthread_create(&data->philo[i]->th, NULL, start_routine,
							   data->philo[i]) != 0)
				return (printf("Error thread create\n"));
		i++;
	}
	return (OK);
}

int main(int argc, char **argv)
{
	t_data *data;

	if (parsing(argc, argv))
		return (ERROR);
	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return (printf("Error memory allocation\n"));
	if (init(argc, argv, data))
	{
		free_all(data); // освободить вообще все
		return (ERROR);
	}
	if (start_treads(data))
	{
		free_all(data); // освободить вообще все
		return (ERROR);
	}
	death_check(); // бесконечный цикл пока один из философов не умрет
	free_all(data); // освободить вообще все
}
