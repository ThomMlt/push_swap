/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toto <toto@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 09:55:57 by toto              #+#    #+#             */
/*   Updated: 2024/12/09 17:16:18 by toto             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

/*il faut que je trouve les best moove, la meilleures conbinaison de chiffre, mais une fois que j'ai trouve il faut que jai
l'indice du nombre en question et l'indice de son cleset lower (si non trouver prendre le max et le mettre pas dessus car 
il devient le nouveau minum de la pile B)

si l'indice dans la pile A > a la taille * 2 donc compte sa position par la fin, si < *2 la size faire  */

int	find_cost(t_stack *piles, int nb)
{
	int	cost_a;
	int	cost_b;
	int index_a;
	int index_closest_b;

	index_a = get_index(piles->p_a, nb);
	if (find_closest_lower_index(piles->p_b, nb) != -1)
		index_closest_b = find_closest_lower_index(piles->p_b, nb);
	else
		index_closest_b = find_max_index(piles->p_b);
	if (index_a * 2 > piles->size_a)
		cost_a = piles->size_a - index_a;
	if (index_a * 2 <= piles->size_a)
		cost_a = index_a;
	if (index_closest_b * 2 > piles->size_b)
		cost_b = piles->size_b - index_closest_b;
	if (index_closest_b * 2 <= piles->size_b)
		cost_b = index_closest_b;
	return (cost_a + cost_b);
}

int	find_cheapest(t_stack *piles)
{
	int		nb_cheapest;
	int		cost;
	int		min_cost;
	t_lst	*current_pa;
	t_lst	*pile_b;

	min_cost = INT_MAX;
	current_pa = piles->p_a;
	pile_b = piles->p_b;
	while (current_pa != NULL)
	{
		cost = (get_index(current_pa, current_pa->nb)
				+ find_closest_lower_index(pile_b, current_pa->nb));
		if (cost < min_cost)
		{
			nb_cheapest = current_pa->nb;
			min_cost = cost;
		}
		current_pa = current_pa->next;
	}
	return (nb_cheapest);
}

void	put_top_cheapest(t_stack *piles, int cheapest)
{
}

void	ft_sort(t_stack *piles)
{
	if (ft_lst_lenght(piles->p_a) > 3)
		push_b(piles);
	if (ft_lst_lenght(piles->p_a) > 3)
		push_b(piles);
}