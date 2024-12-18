/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_index_to_value.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmillot <tmillot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 14:51:40 by thomas            #+#    #+#             */
/*   Updated: 2024/12/18 14:08:16 by tmillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/push_swap.h"

int	ft_index_to_value(t_lst *lst, int index)
{
	int		i;
	t_lst	*l;

	i = 0;
	l = lst;
	while (i < index)
	{
		l = l->next;
		i++;
	}
	return (l->nb);
}
