/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toto <toto@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 16:28:55 by toto              #+#    #+#             */
/*   Updated: 2024/12/05 16:52:04 by toto             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*ft_init(char **argv)
{
	t_stack	*piles;

	piles = malloc(sizeof(t_stack));
	piles->p_a = NULL;
	piles->p_b = NULL;
	build_stack(&piles->p_a, argv);
	piles->size_a = ft_lst_lenght(piles->p_a);
	piles->size_b = 0;
	return (piles);
}