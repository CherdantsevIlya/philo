/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkari <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 17:25:45 by pkari             #+#    #+#             */
/*   Updated: 2021/11/29 17:25:47 by pkari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

static int	ft_nbrlen(int nbr)
{
	int	len;

	len = 1;
	if (nbr < 0)
	{
		len++;
		nbr = nbr * (-1);
	}
	while (nbr >= 10)
	{
		len++;
		nbr = nbr / 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i;

	i = ft_nbrlen(n);
	str = ((char *)malloc(sizeof(char) * (i + 1)));
	if (!str)
		return (NULL);
	str[i--] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		n = n * (-1);
	}
	if (n == 0)
		str[0] = '0';
	while (n > 0)
	{
		str[i] = (n % 10) + 48;
		n = (n / 10);
		i--;
	}
	return (str);
}

static char	*ft_copy1(char const *s1, char *strnew)
{
	size_t	i;

	i = 0;
	while (s1[i] != '\0')
	{
		strnew[i] = s1[i];
		i++;
	}
	return (strnew);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*strnew;

	if (s1 && s2)
	{
		i = ft_strlen(s1);
		j = ft_strlen(s2);
		strnew = (char *)malloc(sizeof(char) * (i + j + 1));
		if (!strnew)
			return (NULL);
		j = 0;
		strnew = ft_copy1(s1, strnew);
		while (s2[j] != '\0')
		{
			strnew[i + j] = s2[j];
			j++;
		}
		strnew[i + j] = '\0';
		free(s2);
		return (strnew);
	}
	return (NULL);
}
