/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmillot <tmillot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 15:32:10 by tmillot           #+#    #+#             */
/*   Updated: 2024/12/18 11:47:34 by tmillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	free_lst(t_lst *pile)
{
	t_lst	*temp;

	while (pile)
	{
		temp = pile;
		pile = pile->next;
		free(temp);
	}
}

void	free_tab_char(char **tab)
{
	int	y;

	y = 0;
	if (tab == NULL)
		return ;
	while (tab[y] != NULL)
	{
		free(tab[y]);
		y++;
	}
	free(tab);
}

void	free_t_stack(t_stack *piles)
{
	free_lst(piles->p_a);
	free_lst(piles->p_b);
	free(piles);
}
