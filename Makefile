# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ljerk <ljerk@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/30 14:07:28 by ljerk             #+#    #+#              #
#    Updated: 2020/08/19 13:08:28 by ljerk            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_C = checker
NAME_P = push_swap

LIB_DIR = ./ft_printf/
LIBFT = $(LIB_DIR)libftprintf.a

SRC_C = ./checker.c ./create_stacks.c ./service.c helpcheck.c ./commands1.c ./commands2.c ft_atoi_ps.c\
		

SRC_P = ./push_swap.c ./create_stacks.c ./service.c helpcheck.c ./commands1.c ./commands2.c ft_atoi_ps.c\
		./solve.c ./count_com.c ./do_com.c ./sort_algo.c 


OBJ_C = $(SRC_C:.c=.o)
OBJ_P = $(SRC_P:.c=.o)

INCLUDE = ./push_swap.h

CC = gcc -g

FLAGS = -Wall -Wextra -Werror

all: $(NAME_C) $(NAME_P)

%.o: %.c
	$(CC) -c $(FLAGS) $<

$(NAME_C): $(OBJ_C)
	$(MAKE) -C $(LIB_DIR)
	$(CC) $(FLAGS) -o $(NAME_C) $(OBJ_C) $(LIBFT)

$(NAME_P): $(OBJ_P)
	$(CC) $(FLAGS) -o $(NAME_P) $(OBJ_P) $(LIBFT)

clean:
	rm -rf $(OBJ_C) $(OBJ_P)
	$(MAKE) -C $(LIB_DIR) clean

fclean: clean
	rm -rf $(NAME_C) $(NAME_P)
	$(MAKE) -C $(LIB_DIR) fclean

re: fclean all