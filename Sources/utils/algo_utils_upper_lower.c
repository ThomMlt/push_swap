/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils_upper_lower.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmillot <tmillot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 13:35:06 by toto              #+#    #+#             */
/*   Updated: 2024/12/18 14:08:09 by tmillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/push_swap.h"

int	find_closest_upper_index(t_lst *pile, int nb)
{
	int		diff;
	int		min_diff;
	int		index;
	int		current_index;
	t_lst	*current;

	current = pile;
	min_diff = INT_MAX;
	current_index = 0;
	index = -1;
	while (current != NULL)
	{
		if (current->nb > nb)
		{
			diff = current->nb - nb;
			if (diff < min_diff)
			{
				min_diff = diff;
				index = current_index;
			}
		}
		current = current->next;
		current_index++;
	}
	return (index);
}

int	find_closest_lower_index(t_lst *pile, int nb)
{
	int		diff;
	int		min_diff;
	int		index;
	int		current_index;
	t_lst	*current;

	current = pile;
	min_diff = INT_MAX;
	current_index = 0;
	index = -1;
	while (current != NULL)
	{
		if (current->nb < nb)
		{
			diff = nb - current->nb;
			if (diff < min_diff)
			{
				min_diff = diff;
				index = current_index;
			}
		}
		current = current->next;
		current_index++;
	}
	return (index);
}
