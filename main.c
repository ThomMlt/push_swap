 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toto <toto@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 16:48:54 by toto              #+#    #+#             */
/*   Updated: 2024/11/29 15:45:26 by toto             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
	(void)argc;
	t_stack *piles;

	piles = ft_init(argv);
	if (ft_parse_push_swap(piles, argv) == FAILURE)
		return (FAILURE);
	ft_sort_under_three_pa(piles);
	while (piles->p_a != NULL)
	{
		ft_printf("%d\n", piles->p_a->nb);
		piles->p_a = piles->p_a->next;
	}
	// ft_printf("size a :%d", piles->size_a);
}

// int main(int argc, char **argv)
// {
// 	(void)argc;
// 	if (handling_error(argv) == 0)
// 		return (0);
// 	t_stack	*piles = malloc(sizeof(t_stack));

// 	piles->p_a = NULL;
// 	piles->p_b = NULL;
// 	piles->size_a = 0;
// 	piles->size_b = 0;
// 	build_stack(&piles->p_a, argv);
// 	reverse_a_b(piles);
// 	t_lst	*pile_b = piles->p_b;
// 	t_lst	*pile_a = piles->p_a;
// 	ft_printf("A	B\n");
// 	if (ft_is_duplicates(piles->p_b) == 0)
// 		return (0);
// 	while (pile_a != NULL)
// 	{
// 		ft_printf("%d	%d\n", pile_a->nb, pile_b->nb);
// 		pile_b = pile_b->next;
// 		pile_a = pile_a->next;
// 	}
// }
