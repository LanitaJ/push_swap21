# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ljerk <ljerk@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/25 16:08:43 by ljerk             #+#    #+#              #
#    Updated: 2020/09/07 12:57:28 by ljerk            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

HEAD = ft_printf.h

LIBFT = ./libft/

.PHONY: all clean fclean re

SRC =	ft_printf.c specificator.c flags.c fourthflags.c star.c\
		spec_c_s.c spec_q.c spec_d.c spec_u.c spec_o.c spec_percent.c spec_x.c\
		spec_b.c spec_p.c spec_f.c\
		ft_service.c spec_morze.c\

OBJ = $(SRC:.c=.o)

OPTION = ./includes/ft_printf.h
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

%.o: %.c $(OPTION)
	@gcc $(FLAGS) -I $(OPTION) -o $@ -c $<

$(NAME): $(OBJ)
	@$(MAKE) -C $(LIBFT)
	@cp libft/libft.a ./$(NAME)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

clean:
	@$(MAKE) clean -C $(LIBFT)
	@/bin/rm -f $(OBJ)

fclean: clean
	@$(MAKE) fclean -C $(LIBFT)
	@/bin/rm -f $(NAME)
	
re: fclean all