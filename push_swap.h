/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toto <toto@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 16:46:54 by toto              #+#    #+#             */
/*   Updated: 2024/12/05 16:36:24 by toto             ###   ########.fr       */
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
int		index_median(t_stack *pile);

#endif