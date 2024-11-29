# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: toto <toto@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/29 14:12:47 by toto              #+#    #+#              #
#    Updated: 2024/11/29 15:14:46 by toto             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = $(wildcard *.c) $(wildcard rules/*.c) $(wildcard erro_handling/*.c) $(wildcard utils/*.c)

OBJS = ${SRC:.c=.o}

CC = cc

CFLAGS = -Wall -Wextra -Werror

MAME = push_swap

LIBFT_DIR = libft

LIBFT_INCLUDE = -I $(LIBFT_DIR)/includes

LIBFT_LIB = $(LIBFT_DIR)/libft.a

all: ${NAME}

${NAME}: $(OBJS) $(LIBFT_LIB)
	$(CC) $(CFLAGS) $(LIBFT_INCLUDE) $(OBJS) -L $(LIBFT_DIR) -lft -o $(NAME)

%.o: %.c
	${CC} ${CFLAGS} $(LIBFT_INCLUDE) -c $< -o $@

$(LIBFT_LIB):
	make -C $(LIBFT_DIR)

clean:
		rm -f ${OBJS}
		make clean -C $(LIBFT_DIR)

fclean: clean
		rm -f ${NAME}
		make fclean -C $(LIBFT_DIR)

re: fclean all