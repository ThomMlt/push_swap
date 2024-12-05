/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max_or_min.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toto <toto@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 11:43:55 by toto              #+#    #+#             */
/*   Updated: 2024/12/05 13:41:45 by toto             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	find_min(t_lst *pile)
{
	int	min;

	min = pile->nb;
	while (pile->next != NULL)
	{
		if (min > pile->nb)
			min = pile->nb;
		pile = pile->next;
	}
	return (min);
}