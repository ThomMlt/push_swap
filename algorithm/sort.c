/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 14:02:11 by thomas            #+#    #+#             */
/*   Updated: 2024/12/11 00:03:40 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_piles_sort(t_stack *piles)
{
	t_lst	*pile_a;

	pile_a = piles->p_a;
	if (pile_a == NULL || pile_a->next == NULL)
		return (SUCCESS);
	while (pile_a != NULL)
	{
		if (pile_a->nb > pile_a->next->nb)
			return (FAILURE);
		pile_a = pile_a->next;
	}
	return (SUCCESS);
}

void	ft_sort_under_three_pa(t_stack *piles)
{
	int	index_max;

	index_max = find_max_index(piles->p_a);
	if (ft_lst_lenght(piles->p_a) > 2)
	{
		if (index_max == 0)
			rotate_a(piles);
		if (index_max == 1)
			reverse_a(piles);
		if (piles->p_a->nb > piles->p_a->next->nb)
			swap_a(piles);
	}
	else if (ft_lst_lenght(piles->p_a) > 1)
		if (piles->p_a->nb > piles->p_a->next->nb)
			swap_a(piles);
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

void	ft_sort(t_stack *piles)
{
    if (check_piles_sort(piles) == FAILURE)
    {
	    if (piles->size_a > 3)
		    push_b(piles);
	    if (piles->size_a > 3)
		    push_b(piles);
        while (piles->size_a > 3)
			find_cheapest_move(piles);
		if (piles->size_a <= 3)
		{
			if (piles->p_b != NULL)
			{
				put_max_b_on_top(piles);
				
			}
            ft_sort_under_three_pa(piles);
		}
    }
}
