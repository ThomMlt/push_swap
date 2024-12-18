/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmillot <tmillot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 16:46:54 by toto              #+#    #+#             */
/*   Updated: 2024/12/18 13:03:13 by tmillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

# define INT_MIN -2147483648
# define INT_MAX 2147483647
# define SUCCESS 1
# define FAILURE 0

typedef struct s_lst
{
	int				nb;
	struct s_lst	*next;
}			t_lst;

typedef struct s_stack
{
	t_lst	*p_a;
	t_lst	*p_b;
	int		size_a;
	int		size_b;
}			t_stack;

/*initialisation*/
t_stack	*ft_init(char **argv);

/*input error hangling*/
int		only_digit(char *str);
long	ft_is_atoi(char *str);
int		handling_error(char **argv);
int		ft_is_duplicates(t_lst *pile);
int		ft_parse_push_swap(t_stack *piles, char **argv);

/*list fonction*/
t_lst	*ft_newlst_int(int nb);
void	ft_addlst_back(t_lst **lst, t_lst *nb);
void	ft_addlst_front(t_lst **lst, t_lst *nb);
void	build_stack(t_lst **stack, char **argv);
int		ft_lst_lenght(t_lst *pile);
void	free_lst(t_lst *pile);
void	free_tab_char(char **tab);
void	free_t_stack(t_stack *piles);

/*utils algo*/
int		ft_index_to_value(t_lst *lst, int index);
void	print_piles(t_stack *piles);
int		find_max(t_lst *pile);
int		find_min(t_lst *pile);
int		find_max_index(t_lst *pile);
int		find_min_index(t_lst *pile);
int		find_closest_upper_index(t_lst *pile, int nb);
int		find_closest_lower_index(t_lst *pile, int nb);

/*rules*/
void	swap_a(t_stack *pile);
void	swap_b(t_stack *pile);
void	swap_a_and_b(t_stack *pile);
void	push_a(t_stack *pile);
void	push_b(t_stack *pile);
void	rotate_a(t_stack *pile);
void	rotate_b(t_stack *pile);
void	rotate_a_b(t_stack *pile);
void	reverse_a(t_stack *pile);
void	reverse_b(t_stack *pile);
void	reverse_a_b(t_stack *pile);

/*Algo*/
void	ft_sort_under_three_pa(t_stack *piles);

/*Cette fonction pernet de trouver le cout de chaque nombre dans pile A
i _nb est l'indice du nombre dans la pile A
i_closest_b est l'entier inferieur le plus proche dans B
A defaut (si -1) c'est qu'il devient le nouveau minimum de B donc on 
souhaite le mettre dessus le max de B

On part du principe que si l'indice d'un des deux est inferieur a l'autre
vaut mieux faire des doubles rotate ou reverse*/
int		find_cost(t_stack *piles, int nb);
int		get_index(t_lst *pile, int nb);
void	find_cheapest_move(t_stack *piles);
void	ft_sort(t_stack *piles);
int		check_piles_sort(t_stack *piles);
void	do_move(t_stack *piles, int index, int nb);

#endif