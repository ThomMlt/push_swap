/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_duplicate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toto <toto@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 12:16:51 by toto              #+#    #+#             */
/*   Updated: 2024/11/29 12:18:52 by toto             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap/push_swap.h"

int	ft_is_duplicates(t_lst *pile)
{
	t_lst	*current;
	t_lst	*run;

	current = pile;
	while (current != NULL)
	{
		run = current->next;
		while (run != NULL)
		{
			if (current->nb == run->nb)
			{
				write_error(0);
				return (0);
			}
			run = run->next;
		}
		current = current->next;
	}
	return (1);
}