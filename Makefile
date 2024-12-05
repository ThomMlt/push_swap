# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: toto <toto@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/29 14:12:47 by toto              #+#    #+#              #
#    Updated: 2024/12/05 16:55:24 by toto             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# SRCS = $(wildcard *.c) $(wildcard rules/*.c) $(wildcard error_handling/*.c) $(wildcard utils/*.c)

# OBJS = ${SRC:.c=.o}

# CC = cc

# CFLAGS = -Wall -Wextra -Werror

# MAME = push_swap

# LIBFT_DIR = libft

# LIBFT_INCLUDE = -I $(LIBFT_DIR)/includes

# LIBFT_LIB = $(LIBFT_DIR)/libft.a

# all: ${NAME}

# ${NAME}: $(OBJS) $(LIBFT_LIB)
# 	$(CC) $(CFLAGS) $(LIBFT_INCLUDE) $(OBJS) -L $(LIBFT_DIR) -lft -o $(NAME)

# %.o: %.c
# 	${CC} ${CFLAGS} $(LIBFT_INCLUDE) -c $< -o $@

# $(LIBFT_LIB):
# 	make -C $(LIBFT_DIR)

# clean:
# 		rm -f ${OBJS}
# 		make clean -C $(LIBFT_DIR)

# fclean: clean
# 		rm -f ${NAME}
# 		make fclean -C $(LIBFT_DIR)

# re: fclean all

# Makefile principal

# Définition des variables
NAME = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = $(wildcard *.c) $(wildcard rules/*.c) $(wildcard error_handling/*.c) $(wildcard utils/*.c) $(wildcard algorithm/*.c) $(wildcard init/*.c)

OBJS = ${SRCS:.c=.o}

LIBFT_DIR = libft

LIBFT_INCLUDE = -I $(LIBFT_DIR)/includes

LIBFT_LIB = $(LIBFT_DIR)/libft.a

# Règle pour la cible 'all'
all: $(NAME)

# Règle pour compiler et linker le programme
$(NAME): $(OBJS) $(LIBFT_LIB)
	$(CC) $(CFLAGS) $(LIBFT_INCLUDE) $(OBJS) -L $(LIBFT_DIR) -lft -o $(NAME)

# Règle pour compiler les fichiers source
%.o: %.c
	$(CC) $(CFLAGS) $(LIBFT_INCLUDE) -c $< -o $@

# Règle pour appeler le Makefile de libft
$(LIBFT_LIB):
	make -C $(LIBFT_DIR)

# Règle pour nettoyer les fichiers objets et l'exécutable
clean:
	rm -f $(OBJS)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean all
	make all
