# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kbagot <kbagot@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/17 17:47:06 by kbagot            #+#    #+#              #
#    Updated: 2017/01/24 18:57:54 by kbagot           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = printf
FLAGS = -Wall -Werror -Wextra #-Wno-format
O_FILES = main.o printf.o print_specifier.o add_prt.o
C_FILES = main.c printf.c print_specifier.c add_prt.c
HEADER_LIBFT = -I libft/includes

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(C_FILES) printf.h
#	make -C libft/ re
	gcc $(FLAGS) $(HEADER_LIBFT) -c $(C_FILES)
	gcc -o $(NAME) $(O_FILES) $(HEADER_LIBFT) -L libft/ -lft
#	gcc -o $(NAME) $(O_FILES) ./libft/*.o $(HEADER_LIBFT) -L libft/ -lft
#	ar rc libftprintf.a $(O_FILES)
#	ranlib libftprintf.a
clean:
	rm -rf $(O_FILES)

fclean: clean
	rm -rf $(NAME)

re: fclean all
