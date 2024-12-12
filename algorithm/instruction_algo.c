/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_algo.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 14:17:13 by thomas            #+#    #+#             */
/*   Updated: 2024/12/12 14:34:18 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	move_1(t_stack *piles, int index, int closest_index)
{
	printf("closest index %d\n", closest_index);
	while (index > 0 && closest_index > 0)
	{
		rotate_a_b(piles);
		index--;
		closest_index--;
	}
	while (index > 0)
	{
		rotate_a(piles);
		index--;
	}
	while (closest_index > 0)
	{
		rotate_b(piles);
		closest_index--;
	}
}

static void	move_2(t_stack *piles, int index, int closest_index)
{
	while ((piles->size_a - index) > 0 && (piles->size_b - closest_index) > 0)
	{
		reverse_a_b(piles);
		index++;
		closest_index++;
	}
	while ((piles->size_a - index) > 0)
	{
		reverse_a(piles);
		index++;
	}
	while ((piles->size_b - closest_index) > 0)
	{
		reverse_b(piles);
		closest_index++;
	}
}

static void	move_3(t_stack *piles, int index, int closest_index)
{
    while (index > 0)
    {
        rotate_a(piles);
        index--;
    }
    while (piles->size_b - closest_index > 0)
    {
        reverse_b(piles);
        closest_index++;
    }
}

static void	move_4(t_stack *piles, int index, int closest_index)
{
	while (piles->size_a - index > 0)
    {
        reverse_a(piles);
        index++;
    }
    while (closest_index > 0)
    {
        rotate_b(piles);
        closest_index--;
    }
}

void	do_move(t_stack *piles, int index, int nb)
{
	int	i_closest_b;

	i_closest_b = find_closest_lower_index(piles->p_b, nb);
	if (i_closest_b == -1)
		i_closest_b = find_max_index(piles->p_b);
	if (index * 2 < piles->size_a && index >= i_closest_b)
	{
		printf("move1\n");
		move_1(piles, index, i_closest_b);
	}
	else if (i_closest_b * 2 < piles->size_b && i_closest_b >= index)
	{
		printf("move1_2\n");
		move_1(piles, index, i_closest_b);
	}
	else if (index * 2 >= piles->size_a
		&& (piles->size_a - index) >= (piles->size_b - i_closest_b))
	{
		printf("move2\n");	
		move_2(piles, index, i_closest_b);
	}
	else if (i_closest_b * 2 >= piles->size_b
		&& (piles->size_a - index) <= (piles->size_b - i_closest_b))
	{
		printf("move2_2\n");	
		move_2(piles, index, i_closest_b);
	}
	else if (index * 2 < piles->size_a && i_closest_b * 2 >= piles->size_b)
	{
	printf("move3\n");		
		move_3(piles, index, i_closest_b);
	}
	else if (index * 2 >= piles->size_a && i_closest_b * 2 < piles->size_b)
	{
		printf("move4\n");	
		move_4(piles, index, i_closest_b);
	}
	push_b(piles);
}
