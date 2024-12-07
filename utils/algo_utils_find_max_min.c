/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils_find_max_min.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toto <toto@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 12:47:39 by toto              #+#    #+#             */
/*   Updated: 2024/12/07 13:42:51 by toto             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	find_max(t_lst *pile)
{
	int	max;

	max = pile->nb;
	while (pile)
	{
		if (max < pile->nb)
			max = pile->nb;
		pile = pile->next;
	}
	return (max);
}

int	find_min(t_lst *pile)
{
	int	min;

	min = pile->nb;
	while (pile)
	{
		if (min > pile->nb)
			min = pile->nb;
		pile = pile->next;
	}
	return (min);
}

int	find_max_index(t_lst *pile)
{
	int		max;
	int		i;
	t_lst	*current;

	max = find_max(pile);
	i = 0;
	current = pile;
	while (current != NULL)
	{
		if (current->nb == max)
			return (i);
		current = current->next;
		i++;
	}
	return (-1);
}

int	find_min_index(t_lst *pile)
{
	int		min;
	int		i;
	t_lst	*current;

	min = find_min(pile);
	i = 0;
	current = pile;
	while (current != NULL)
	{
		if (current->nb == min)
			return (i);
		current = current->next;
		i++;
	}
	return (-1);
}
