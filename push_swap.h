/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toto <toto@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 16:46:54 by toto              #+#    #+#             */
/*   Updated: 2024/11/25 14:56:43 by toto             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

# define INT_MIN -2147483648
# define INT_MAX 2147483647

typedef struct s_stack
{
	int	nb;
	struct s_stack	*next_nb;
}			t_stack;




#endif