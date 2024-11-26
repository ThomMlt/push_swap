/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toto <toto@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 16:46:54 by toto              #+#    #+#             */
/*   Updated: 2024/11/26 13:54:46 by toto             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

# define INT_MIN -2147483648
# define INT_MAX 2147483647

typedef struct s_stack
{
	int				nb;
	struct s_stack	*next;
}			t_stack;

/*input error hangling*/
void	write_error(int c);
int		only_digit(char *str);
long	ft_atoi_pushswap(char *str);
int		ft_is_int(long nb);
int		handling_error(char **argv);

/**/
t_stack	*ft_newlst_int(int nb);
void	ft_addlst_stack(t_stack **lst, t_stack *nb);
void	build_stack(t_stack **stack, char **argv);

#endif