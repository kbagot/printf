# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kbagot <kbagot@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/17 17:47:06 by kbagot            #+#    #+#              #
#    Updated: 2017/02/09 15:39:05 by kbagot           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
FLAGS = -Wall -Werror -Wextra #-Wno-format
O_FILES = add_length.o make_char_specif.o make_specifier.o precision_mod.o tools_convert.o width_mod.o printf.o add_prt.o init_sub_specif.o ./libft/*.o
C_FILES = add_length.c make_char_specif.c make_specifier.c precision_mod.c tools_convert.c width_mod.c printf.c add_prt.c init_sub_specif.c ./libft/*.c
HEADER_LIBFT = -I libft/includes

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(C_FILES)
	make -C libft/ re
	gcc -c $(FLAGS) $(C_FILES) $(HEADER_LIBFT)
#	gcc -o $(NAME) printf.o print_specifier.o add_prt.o $(HEADER_LIBFT) -L libft/ -lft
#	gcc -o $(NAME) $(O_FILES)
	ar rc libftprintf.a $(O_FILES)
	ranlib libftprintf.a
clean:
	rm -rf *.o
fclean: clean
	rm -rf $(NAME)

re: fclean all
