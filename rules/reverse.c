/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 10:33:15 by toto              #+#    #+#             */
/*   Updated: 2024/12/12 14:25:43 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap/push_swap.h"

void	reverse_a(t_stack *pile)
{
	t_lst	*last;
	t_lst	*penultimate;

	last = pile->p_a;
	penultimate = pile->p_a;
	while (last->next != NULL)
		last = last->next;
	while (penultimate->next->next != NULL)
		penultimate = penultimate->next;
	last->next = pile->p_a;
	pile->p_a = last;
	penultimate->next = NULL;
	ft_printf("rra\n");
}

void	reverse_b(t_stack *pile)
{
	t_lst	*last;
	t_lst	*penultimate;

	last = pile->p_b;
	penultimate = pile->p_b;
	while (last->next != NULL)
		last = last->next;
	while (penultimate->next->next != NULL)
		penultimate = penultimate->next;
	last->next = pile->p_b;
	pile->p_b = last;
	penultimate->next = NULL;
	ft_printf("rrb\n");
}

void	reverse_a_b(t_stack *pile)
{
	t_lst	*last;
	t_lst	*penultimate;

	last = pile->p_b;
	penultimate = pile->p_b;
	while (last->next != NULL)
		last = last->next;
	while (penultimate->next->next != NULL)
		penultimate = penultimate->next;
	last->next = pile->p_b;
	pile->p_b = last;
	penultimate->next = NULL;
	last = pile->p_a;
	penultimate = pile->p_a;
	while (last->next != NULL)
		last = last->next;
	while (penultimate->next->next != NULL)
		penultimate = penultimate->next;
	last->next = pile->p_a;
	pile->p_a = last;
	penultimate->next = NULL;
	ft_printf("rrr\n");
}
