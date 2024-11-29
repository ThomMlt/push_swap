/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toto <toto@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 16:46:54 by toto              #+#    #+#             */
/*   Updated: 2024/11/29 18:17:58 by toto             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

# define INT_MIN -2147483648
# define INT_MAX 2147483647

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

/*input error hangling*/
void	write_error(int c);
int		only_digit(char *str);
long	ft_atoi_pushswap(char *str);
int		ft_is_int(long nb);
int		handling_error(char **argv);

/**/
t_lst	*ft_newlst_int(int nb);
void	ft_addlst_stack(t_lst **lst, t_lst *nb);
void	build_stack(t_lst **stack, char **argv);
int		ft_is_duplicates(t_lst *pile);
int		ft_lst_lenght(t_lst *pile);

/*rules*/
void	swap_a(t_stack *pile);
void	swap_b(t_stack *pile);
void	swap_a_and_b(t_stack *pile);

#endif