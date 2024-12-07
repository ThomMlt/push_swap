/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toto <toto@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 09:55:57 by toto              #+#    #+#             */
/*   Updated: 2024/12/07 16:33:19 by toto             ###   ########.fr       */
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
