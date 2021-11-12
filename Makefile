# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ael-kass <ael-kass@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/03 11:17:34 by ael-kass          #+#    #+#              #
#    Updated: 2021/11/11 23:18:27 by ael-kass         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = ./srcs/mandatory/parsing.c \
		./srcs/mandatory/tools.c \
		./srcs/mandatory/operations.c \
		./srcs/mandatory/small_stack.c \
		./srcs/mandatory/big_stack.c \
		./srcs/mandatory/main.c

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