/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toto <toto@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 18:40:48 by toto              #+#    #+#             */
/*   Updated: 2024/11/30 15:35:37 by toto             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap/push_swap.h"

void	push_a(t_stack *pile)
{
	t_lst	*first_b;

	first_b = pile->p_b;
	ft_addlst_front(&pile->p_a, first_b);
	pile->p_b = pile->p_b->next;
	ft_printf("pa\n");
}

void	push_b(t_stack *pile)
{
	t_lst	*first_a;

	first_a = pile->p_a;
	ft_addlst_front(&pile->p_b, first_a);
	pile->p_a = pile->p_a->next;
	ft_printf("pb\n");
}
