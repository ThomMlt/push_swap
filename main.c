/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmillot <tmillot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 16:48:54 by toto              #+#    #+#             */
/*   Updated: 2024/12/18 12:56:06 by tmillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*piles;

	if (argc <= 1)
		return (ft_putstr_fd("error\n", 2), FAILURE);
	piles = ft_init(argv);
	if (piles == NULL)
		return (FAILURE);
	if (ft_parse_push_swap(piles, argv) == FAILURE)
		return (free_t_stack(piles), FAILURE);
	else
	{
		ft_sort(piles);
		free_t_stack(piles);
		return (SUCCESS);
	}
}
