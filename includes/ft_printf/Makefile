# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lfabel <lfabel@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/12 10:36:55 by lfabel            #+#    #+#              #
#    Updated: 2024/08/12 12:36:02 by lfabel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

CC		=	cc

CFLAGS	=	-Wall -Werror -Wextra

INCLUDE = includes

SRC		=	ft_printf.c\
				ft_print_hex.c\
				ft_print_nbr.c\
				ft_print_uns.c\
				ft_print_ptr.c\
				ft_helpers.c

OBJ		=	ft_printf.o\
				ft_print_hex.o\
				ft_print_nbr.o\
				ft_print_uns.o\
				ft_print_ptr.o\
				ft_helpers.o

all: $(NAME)


$(NAME): $(OBJ)
		ar -rcs $(NAME) $(OBJ)

clean: 
		rm -rf $(OBJ)

fclean: clean
		rm -f $(NAME)

re: 	fclean all

.PHONY: clean all fclean re