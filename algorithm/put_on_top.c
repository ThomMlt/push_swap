/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_on_top.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmillot <tmillot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 12:59:54 by tmillot           #+#    #+#             */
/*   Updated: 2024/12/18 13:00:46 by tmillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	put_min_a_on_top(t_stack *piles)
{
	int	index_min;

	index_min = find_min_index(piles->p_a);
	if (index_min * 2 < piles->size_a)
		while (index_min-- > 0)
			rotate_a(piles);
	if (index_min * 2 >= piles->size_a)
	{
		while (index_min < piles->size_a)
		{
			reverse_a(piles);
			index_min++;
		}
	}
}

void	put_max_b_on_top(t_stack *piles)
{
	int	max_index;

	max_index = find_max_index(piles->p_b);
	if (max_index * 2 < piles->size_b)
	{
		while (max_index > 0)
		{
			rotate_b(piles);
			max_index--;
		}
	}
	else
	{
		while (max_index < piles->size_b)
		{
			reverse_b(piles);
			max_index++;
		}
	}
}
