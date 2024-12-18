/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmillot <tmillot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 17:39:27 by toto              #+#    #+#             */
/*   Updated: 2024/12/16 16:52:20 by tmillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap_a(t_stack *pile)
{
	t_lst	*first;
	t_lst	*second;
	t_lst	*tmp;

	first = pile->p_a;
	second = pile->p_a->next;
	tmp = pile->p_a->next->next;
	pile->p_a = second;
	pile->p_a->next = first;
	first->next = tmp;
	ft_printf("sa\n");
}

void	swap_b(t_stack *pile)
{
	t_lst	*first;
	t_lst	*second;
	t_lst	*tmp;

	first = pile->p_b;
	second = pile->p_b->next;
	tmp = pile->p_b->next->next;
	pile->p_b = second;
	pile->p_b->next = first;
	first->next = tmp;
	ft_printf("sb\n");
}

void	swap_a_and_b(t_stack *pile)
{
	t_lst	*first_a;
	t_lst	*second_a;
	t_lst	*tmp;
	t_lst	*first_b;
	t_lst	*second_b;

	first_a = pile->p_a;
	second_a = pile->p_a->next;
	tmp = pile->p_a->next->next;
	pile->p_a = second_a;
	pile->p_a->next = first_a;
	first_a->next = tmp;
	first_b = pile->p_b;
	second_b = pile->p_b->next;
	tmp = pile->p_b->next->next;
	pile->p_b = second_b;
	pile->p_b->next = first_b;
	first_b->next = tmp;
	ft_printf("ss\n");
}
