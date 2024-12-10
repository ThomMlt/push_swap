/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_cheapest.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 09:55:57 by toto              #+#    #+#             */
/*   Updated: 2024/12/11 00:03:45 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	get_index(t_lst *pile, int nb)
{
	int		i;

	i = 0;
	while (pile->nb != nb && pile != NULL)
	{
		i++;
		pile = pile->next;
	}
	return (i);
}

int	find_cost(t_stack *piles, int nb)
{
	int	cost;
	int	i_nb;
	int	i_closest_b;

	cost = 0;
	i_nb = get_index(piles->p_a, nb);
	i_closest_b = find_closest_lower_index(piles->p_b, nb);
	if (i_closest_b == -1)
		i_closest_b = find_max_index(piles->p_b);
	if (i_nb * 2 < piles->size_a && i_nb >= i_closest_b) 
		cost = i_nb;
	else if (i_closest_b * 2 < piles->size_b && i_closest_b >= i_nb)
		cost = i_closest_b;
	else if (i_nb * 2 >= piles->size_a && (piles->size_a - i_nb) >= (piles->size_b - i_closest_b))
		cost = piles->size_a - i_nb;
	else if (i_closest_b * 2 >= piles->size_b && (piles->size_a - i_nb) <= (piles->size_b - i_closest_b))
		cost = piles->size_b - i_closest_b;
	else if (i_nb * 2 < piles->size_a && i_closest_b * 2 >= piles->size_b)
		cost = i_nb + (piles->size_b + i_closest_b);
	else if (i_nb * 2 >= piles->size_a && i_closest_b * 2 < piles->size_b)
		cost = i_closest_b + (piles->size_a - i_nb);
	return (cost);
}

void	find_cheapest_move(t_stack *piles)
{
	int		index_nb;
	int		nb;
	int		cost;
	int		min_cost;
	t_lst	*current_pa;

	min_cost = (piles, piles->p_a->nb);
	index_nb = 0;
	current_pa = piles->p_a->next;
	while (current_pa != NULL)
	{
		cost = find_cost(piles, current_pa->nb);
		if (cost < min_cost)
		{
			index_nb = get_index(current_pa, current_pa->nb);
			nb = current_pa->nb;
			min_cost = cost;
		}
		current_pa = current_pa->next;
	}
	do_move(piles, index_nb, nb);
}
