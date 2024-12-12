/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_piles.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 15:14:09 by thomas            #+#    #+#             */
/*   Updated: 2024/12/12 15:18:18 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	print_piles(t_stack *piles)
{
	t_lst *l;

	l = piles->p_a;
	printf("\npile a : ");
	while (l != NULL)
	{
		printf("%d ", l->nb);
		l = l->next;
	}
	printf("\npile b : ");
	l = piles->p_b;
	while (l != NULL)
	{
		printf("%d ", l->nb);
		l = l->next;
	}
	printf("\n");
}
