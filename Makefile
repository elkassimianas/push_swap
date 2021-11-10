# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ael-kass <ael-kass@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/03 11:17:34 by ael-kass          #+#    #+#              #
#    Updated: 2021/11/08 11:31:30 by ael-kass         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = parsing.c \
		tools.c \
		operations.c \
		small_stack.c \
		main.c

FLAGS = -Wall -Wextra -Werror

CC = gcc -g

LIB = ./Libft/libft.a

HEADER = libft.h

all: $(NAME)

$(NAME): $(LIB) $(SRC)
	@$(CC) $(FLAGS) $(SRC) $(LIB) -o $(NAME)

$(LIB):
	@make -C ./Libft

clean:
	@make -C ./Libft fclean
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)

re: fclean all