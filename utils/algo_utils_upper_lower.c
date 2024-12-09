/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils_upper_lower.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toto <toto@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 13:35:06 by toto              #+#    #+#             */
/*   Updated: 2024/12/09 16:44:00 by toto             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// ft_ next upper index 
// ft_ next lower index

int	find_closet_upper_index(t_lst *pile, int nb)
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
