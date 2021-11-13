# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ael-kass <ael-kass@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/03 11:17:34 by ael-kass          #+#    #+#              #
#    Updated: 2021/11/13 21:38:14 by ael-kass         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

NAME_BONUS = checker

SRC = ./srcs/mandatory/parsing.c \
		./srcs/mandatory/tools.c \
		./srcs/mandatory/operations.c \
		./srcs/mandatory/small_stack.c \
		./srcs/mandatory/big_stack.c \
		./srcs/mandatory/small_stack_tools.c \
		./srcs/mandatory/merge_sort.c \
		./srcs/mandatory/main.c

SRC_BONUS = ./srcs/bonus/parsing_bonus.c \
			./srcs/bonus/tools_bonus.c \
			./srcs/bonus/main_bonus.c \
			./srcs/bonus/operations_bonus1.c \
			./srcs/bonus/get_next_line/get_next_line_bonus.c \
			./srcs/bonus/get_next_line/get_next_line_utils_bonus.c

INCLUDES =  ./includes/push_swap.h

INCLUDES_BONUS = ./includes/push_swap_bonus.h \
					./includes/get_next_line_bonus.h

FLAGS = -Wall -Wextra -Werror -fsanitize=address

CC = gcc -g

LIB = ./Libft/libft.a

HEADER = libft.h

all: $(NAME) $(LIB)

$(NAME): $(LIB) $(SRC) $(INCLUDES)
	@$(CC) $(FLAGS) $(SRC) $(LIB) -o $(NAME)

bonus: $(NAME_BONUS) $(LIB)

$(NAME_BONUS): $(LIB) $(SRC_BONUS) $(INCLUDES_BONUS)
	@$(CC) $(FLAGS) $(SRC_BONUS) $(LIB) -o $(NAME_BONUS)

$(LIB):
	@make -C ./Libft

clean:
	@make -C ./Libft fclean

fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(NAME_BONUS)
	@make -C ./Libft fclean

re: fclean all
