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