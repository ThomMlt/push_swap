/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toto <toto@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 11:21:43 by toto              #+#    #+#             */
/*   Updated: 2024/11/25 15:43:56 by toto             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap/push_swap.h"

void	write_error(int c)
{
	if (c == 0)
		ft_putstr_fd("error\n", 2);
}

int	only_digit(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '-' || str[0] == '+')
		i++;
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]) == 0)
		{
			write_error(0);
			return (0);
		}
		i++;
	}
	return (1);
}

long	ft_atoi_pushswap(char *str)
{
	int		sign;
	long	result;
	int		i;

	sign = 1;
	i = 0;
	result = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (sign * result);
}

int	ft_is_int(long nb)
{
	if (nb >= INT_MIN && nb <= INT_MAX)
		return (1);
	else
		return (0);
}

int	handling_error(char **argv)
{
	int		i;
	int		j;
	char	**str;

	i = 1;
	while (argv[i] != NULL)
	{
		str = ft_split(argv[i], ' ');
		j = 0;
		while (str[j] != NULL)
		{
			if (only_digit(str[j]) == 0)
				return (0);
			if (ft_is_int(ft_atoi_pushswap(str[j])) == 0)
				return (write_error(0), 0);
			j++;
		}
		i++;
	}
	return (1);
}
