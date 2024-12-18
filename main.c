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
	t_stack	*piles;

	if (argc <= 1)
		return (ft_putstr_fd("error\n", 2), FAILURE);
	piles = ft_init(argv);
	if (ft_parse_push_swap(piles, argv) == FAILURE)
		return (free_lst(piles->p_a), FAILURE);
	else
	{
		ft_sort(piles);
		while (piles->p_a)
		{
			ft_printf("%d\n", piles->p_a->nb);
			piles->p_a = piles->p_a->next;
		}
		free_lst(piles->p_a);
		free(piles);
	}
}
