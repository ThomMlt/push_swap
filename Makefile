# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmillot <tmillot@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/29 14:12:47 by toto              #+#    #+#              #
#    Updated: 2024/12/18 14:48:09 by tmillot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror -g

SRCS = Sources/algorithme/find_cheapest.c \
		Sources/algorithme/instruction_algo.c \
		Sources/algorithme/put_on_top.c \
		Sources/algorithme/sort.c \
		Sources/error_handling/input_error.c \
		Sources/init/ft_init.c \
		Sources/main/main.c \
		Sources/rules/push.c \
		Sources/rules/reverse.c \
		Sources/rules/rotate.c \
		Sources/rules/swap.c \
		Sources/utils/algo_utils_find_max_min.c \
		Sources/utils/algo_utils_upper_lower.c \
		Sources/utils/free.c \
		Sources/utils/ft_index_to_value.c \
		Sources/utils/lst_utils.c \
		Sources/utils/print_piles.c \

OBJS = ${SRCS:.c=.o}

LIBFT_DIR = Sources/libft

LIBFT_INCLUDE = -I $(LIBFT_DIR)/includes

LIBFT_LIB = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_LIB)
	$(CC) $(CFLAGS) $(LIBFT_INCLUDE) $(OBJS) -L $(LIBFT_DIR) -lft -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(LIBFT_INCLUDE) -c $< -o $@

$(LIBFT_LIB):
	make -C $(LIBFT_DIR)

clean:
	rm -f $(OBJS)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean all
