/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmillot <tmillot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 14:02:11 by thomas            #+#    #+#             */
/*   Updated: 2024/12/18 14:29:51 by tmillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/push_swap.h"

int	check_piles_sort(t_stack *piles)
{
	t_lst	*pile_a;

	pile_a = piles->p_a;
	if (pile_a == NULL || pile_a->next == NULL)
		return (SUCCESS);
	while (pile_a->next != NULL)
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

t_lst	*ft_lstlast_ps(t_lst *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	push_back_a(t_stack *piles)
{
	t_lst	*first_b;
	int		next_upper;

	first_b = piles->p_b;
	next_upper = find_closest_upper_index(piles->p_a, first_b->nb);
	if (next_upper == -1)
		next_upper = find_min_index(piles->p_a);
	if (next_upper * 2 < piles->size_a)
		while (next_upper-- > 0)
			rotate_a(piles);
	else
		while (next_upper++ < piles->size_a)
			reverse_a(piles);
	push_a(piles);
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
			ft_sort_under_three_pa(piles);
			if (piles->p_b != NULL)
			{
				put_max_b_on_top(piles);
				while (piles->p_b != NULL)
					push_back_a(piles);
				put_min_a_on_top(piles);
			}
			free_lst(piles->p_b);
		}
	}
}
