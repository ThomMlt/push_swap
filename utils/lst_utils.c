/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toto <toto@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 12:40:22 by toto              #+#    #+#             */
/*   Updated: 2024/11/29 12:21:18 by toto             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap/push_swap.h"

t_lst	*ft_newlst_int(int nb)
{
	t_lst	*dest;

	dest = malloc(sizeof(t_lst));
	if (!dest)
		return (NULL);
	dest->nb = nb;
	dest->next = NULL;
	return (dest);
}

void	ft_addlst_stack(t_lst **lst, t_lst *nb)
{
	t_lst	*last;

	if (lst == NULL || nb == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = nb;
		return ;
	}
	last = *lst;
	while (last->next != NULL)
		last = last->next;
	last->next = nb;
}

void	build_stack(t_lst **stack, char **argv)
{
	int		i;
	int		j;
	char	**str;

	i = 1;
	while (argv[i] != NULL)
	{
		str = ft_split(argv[i], ' ');
		j = 0;
		while (str[j] != NULL)
		{
			ft_addlst_stack(stack, ft_newlst_int(ft_atoi(str[j])));
			j++;
		}
		i++;
	}
}

int	ft_lst_lenght(t_lst *pile)
{
	int	i;

	i = 0;
	while (pile != NULL)
	{
		i++;
		pile = pile->next;
	}
	return (i);
}

// int main(int argc, char **argv)
// {
// 	t_stack *pile_a;

// 	pile_a = NULL;
// 	build_stack(&pile_a, argv);
// 	ft_is_duplicates(pile_a);
// 	while (pile_a != NULL)
// 	{
// 		printf("%d\n", pile_a->nb);
// 		pile_a = pile_a->next;
// 	}
// }