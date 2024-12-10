/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_algo.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 14:17:13 by thomas            #+#    #+#             */
/*   Updated: 2024/12/10 18:23:22 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*les deux premiers if c'est double rotate
les deux suivant double reverse 
rotate a et reverse b
rotate b et reverse a*/

static void	move_1(t_stack *piles, int index, int closest_index)
{
	while (index > 0 && closest_index > 0)
	{
		rotate_a_b(piles);
		index--;
		closest_index--;
	}
	if (index > 0)
		while (index > 0)
		{
			rotate_a(piles);
			index--;
		}
	if (closest_index > 0)
		while (closest_index > 0)
		{
			rotate_b(piles);
		}
}

static void	move_2(t_stack *piles, int index, int closest_index)
{
	
}

void	do_move(t_stack *piles, int index, int nb)
{
	int	i_closest_b;

	i_closest_b = find_closest_lower_index(piles->p_b, nb);
	if (i_closest_b == -1)
		i_closest_b = find_max_index(piles->p_b);
	if (index * 2 < piles->size_a && index >= i_closest_b)
		move_1(piles, index, i_closest_b);
	else if (i_closest_b * 2 < piles->size_b && i_closest_b >= index)
		move_1(piles, index, i_closest_b);
	else if (index * 2 >= piles->size_a && (piles->size_a - index) >= (piles->size_b - i_closest_b))
		/*ici double reverse tant que closest b n'est pas sur son top apres revers simple de a
		pour que nb soit sur son top*/
	else if (i_closest_b * 2 >= piles->size_b && (piles->size_a - index) <= (piles->size_b - i_closest_b))
		/*ici double reserve tant que nb n'est pas sur son top 
		reverse simple pour mettre closest b sur son top*/
	else if (index * 2 < piles->size_a && i_closest_b * 2 >= piles->size_b)
		/*relou ici rotate pour mettre nb sur son top
		et reverse pour mettre closest b sur son top*/
	else if (index * 2 >= piles->size_a && i_closest_b * 2 < piles->size_b)
		/*relou aussi reverse sur a pour mettre nb sur son b et rotate pour 
		mettre le closest b sur son top*/
	}
