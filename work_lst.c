/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_lst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toto <toto@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 12:40:22 by toto              #+#    #+#             */
/*   Updated: 2024/11/26 16:22:14 by toto             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_newlst_int(int nb)
{
	t_stack	*dest;

	dest = malloc(sizeof(t_stack));
	if (!dest)
		return (NULL);
	dest->nb = nb;
	dest->next = NULL;
	return (dest);
}

void	ft_addlst_stack(t_stack **lst, t_stack *nb)
{
	t_stack	*last;

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

void	build_stack(t_stack **stack, char **argv)
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

int	ft_is_duplicates(t_stack *pile)
{
	t_stack	*current;
	t_stack	*run;

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