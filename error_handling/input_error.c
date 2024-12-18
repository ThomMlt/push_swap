/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmillot <tmillot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 11:21:43 by toto              #+#    #+#             */
/*   Updated: 2024/12/18 12:55:39 by tmillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	only_digit(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '-' || str[0] == '+')
		i++;
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]) == 0)
			return (FAILURE);
		i++;
	}
	return (SUCCESS);
}

long	ft_is_atoi(char *str)
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
	result *= sign;
	if (result >= INT_MIN && result <= INT_MAX)
		return (SUCCESS);
	else
		return (FAILURE);
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
			if (only_digit(str[j]) == FAILURE || ft_is_atoi(str[j]) == FAILURE)
			{
				free_tab_char(str);
				return (FAILURE);
			}
			j++;
		}
		free_tab_char(str);
		i++;
	}
	return (SUCCESS);
}

int	ft_is_duplicates(t_lst *pile_a)
{
	t_lst	*current;
	t_lst	*run;

	current = pile_a;
	while (current != NULL)
	{
		run = current->next;
		while (run != NULL)
		{
			if (current->nb == run->nb)
				return (FAILURE);
			run = run->next;
		}
		current = current->next;
	}
	return (SUCCESS);
}

int	ft_parse_push_swap(t_stack *piles, char **argv)
{
	if (handling_error(argv) == FAILURE
		|| ft_is_duplicates(piles->p_a) == FAILURE
		|| piles->p_a == NULL)
	{
		ft_putstr_fd("error\n", 2);
		return (FAILURE);
	}
	return (SUCCESS);
}
