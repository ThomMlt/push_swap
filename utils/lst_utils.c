/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmillot <tmillot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 12:40:22 by toto              #+#    #+#             */
/*   Updated: 2024/12/18 12:21:32 by tmillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

void	ft_addlst_back(t_lst **lst, t_lst *nb)
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

void	ft_addlst_front(t_lst **lst, t_lst *nb)
{
	nb->next = *lst;
	*lst = nb;
}

void	build_stack(t_lst **stack, char **argv)
{
	int		i;
	int		j;
	char	**str;

	i = 1;
	if (handling_error(argv) == SUCCESS)
	{
		while (argv[i] != NULL)
		{
			str = ft_split(argv[i], ' ');
			j = 0;
			while (str[j] != NULL)
			{
				ft_addlst_back(stack, ft_newlst_int(ft_atoi(str[j])));
				j++;
			}
			free_tab_char(str);
			i++;
		}
	}
	else
		*stack = NULL;
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