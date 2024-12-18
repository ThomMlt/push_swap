/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmillot <tmillot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 16:25:53 by toto              #+#    #+#             */
/*   Updated: 2024/12/16 16:49:02 by tmillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate_a(t_stack *pile)
{
	t_lst	*first;
	t_lst	*last;

	first = pile->p_a;
	last = pile->p_a;
	while (last->next != NULL)
		last = last->next;
	pile->p_a = first->next;
	last->next = first;
	first->next = NULL;
	ft_printf("ra\n");
}

void	rotate_b(t_stack *pile)
{
	t_lst	*first;
	t_lst	*last;

	first = pile->p_b;
	last = pile->p_b;
	while (last->next != NULL)
		last = last->next;
	pile->p_b = first->next;
	last->next = first;
	first->next = NULL;
	ft_printf("rb\n");
}

void	rotate_a_b(t_stack *pile)
{
	t_lst	*first_a;
	t_lst	*first_b;
	t_lst	*last_a;
	t_lst	*last_b;

	first_a = pile->p_a;
	first_b = pile->p_b;
	last_a = pile->p_a;
	last_b = pile->p_b;
	while (last_a->next != NULL)
		last_a = last_a->next;
	while (last_b->next != NULL)
		last_b = last_b->next;
	pile->p_a = first_a->next;
	pile->p_b = first_b->next;
	last_a->next = first_a;
	last_b->next = first_b;
	first_a->next = NULL;
	first_b->next = NULL;
	ft_printf("rr\n");
}
