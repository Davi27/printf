# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: damartin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/04 13:57:41 by damartin          #+#    #+#              #
#    Updated: 2022/05/04 13:57:45 by damartin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libftprintf.a
CC = clang
C_FLAGS = -Wall -Wextra -Werror

C_SOURCE := ft_printf.c				\
			print_char.c			\
			print_hexa.c			\
			print_ptr.c				\
			print_signed.c			\
			print_unsigned.c		\
			Libft/ft_putchar_fd.c	\
			Libft/ft_itoa.c			\
			Libft/ft_strdup.c		\
			Libft/ft_strlen.c		\

OBJ = $(C_SOURCE:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
		@ar r $(NAME) $(OBJ)

%.o: %.c ft_printf.h
		$(CC) $(C_FLAGS) -c $< -o $@

clean:
		rm -rf $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re