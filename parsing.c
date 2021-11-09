#include "philo.h"

void rules(void)
{
	printf("./philo NP TD TE TS [NM]\n\n");
	printf("	NP - number of philosophers\n");
	printf("	TD - time to die\n");
	printf("	TE - time to eat\n");
	printf("	TS - time to sleep\n");
	printf("	NM - number of times each philosopher must eat\n");
}

int is_num(char *str)
{
	int i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'
		   || str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] >= 48 && str[i] <= 57)
			i++;
		else
			return (ERROR);
	}
	return (OK);
}

int parsing(int argc, char **argv)
{
	if (argc != 5 && argc != 6)
	{
		rules();
		return (ERROR);
	}
	if (is_num(argv[1]) || is_num(argv[2]) || is_num(argv[3])
		|| is_num(argv[4]))
	{
		rules();
		return (ERROR);
	}
	if (argc == 6)
	{
		if (is_num(argv[5]))
		{
			rules();
			return (ERROR);
		}
	}
	return (OK);
}
