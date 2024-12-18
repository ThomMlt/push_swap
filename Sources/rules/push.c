/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmillot <tmillot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 18:40:48 by toto              #+#    #+#             */
/*   Updated: 2024/12/18 14:07:48 by tmillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/push_swap.h"

void	push_a(t_stack *pile)
{
	t_lst	*first_b;

	first_b = pile->p_b;
	pile->p_b = pile->p_b->next;
	ft_addlst_front(&pile->p_a, first_b);
	pile->size_b -= 1;
	pile->size_a += 1;
	ft_printf("pa\n");
}

void	push_b(t_stack *pile)
{
	t_lst	*first_a;

	first_a = pile->p_a;
	pile->p_a = pile->p_a->next;
	ft_addlst_front(&pile->p_b, first_a);
	pile->size_a -= 1;
	pile->size_b += 1;
	ft_printf("pb\n");
}
