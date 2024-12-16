/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmillot <tmillot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 15:32:10 by tmillot           #+#    #+#             */
/*   Updated: 2024/12/16 16:02:53 by tmillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	free_lst(t_lst *pile)
{
	t_lst	*next;

	while (pile != NULL)
	{
		next = pile->next;
		free(pile);
		pile = next;
	}
	pile = NULL;
}

void	free_tab_char(char **tab)
{
	int	y;
	
	y = 0;
	while (tab[y] != NULL)
	{
		y++;
	}
	while (y >= 0)
	{
		free(tab[y]);
		y--;
	}
	free(tab);
}