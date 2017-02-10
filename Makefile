# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kbagot <kbagot@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/17 17:47:06 by kbagot            #+#    #+#              #
#    Updated: 2017/02/10 18:52:21 by kbagot           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
FLAGS = -Wall -Werror -Wextra
C_FILES = add_length.c make_char_specif.c make_specifier.c precision_mod.c tools_convert.c width_mod.c printf.c add_prt.c init_sub_specif.c tools_uni.c tools_convert_uni.c
O_FILES = $(C_FILES:.c=.o)
SRCS_LIBFT = ft_atoi.o ft_bzero.o ft_isalnum.o ft_isalpha.o ft_isascii.o ft_isdigit.o ft_isprint.o ft_itoa.o ft_memccpy.o ft_memchr.o ft_memcmp.o ft_memcpy.o ft_memdel.o ft_memalloc.o ft_memmove.o ft_memset.o ft_putchar.o ft_putchar_fd.o ft_putendl.o ft_putendl_fd.o ft_putnbr.o ft_putnbr_fd.o ft_putstr.o ft_putstr_fd.o ft_strcat.o ft_strchr.o ft_strclr.o ft_strcmp.o ft_strcpy.o ft_strdel.o ft_strdup.o ft_strequ.o ft_striter.o ft_striteri.o ft_strjoin.o ft_strlcat.o ft_strlen.o ft_strmap.o ft_strmapi.o ft_strncat.o ft_strncmp.o ft_strncpy.o ft_strnequ.o ft_strnew.o ft_strnstr.o ft_strrchr.o ft_strsplit.o ft_strstr.o ft_strsub.o ft_strtrim.o ft_tolower.o ft_toupper.o ft_lstnew.o ft_lstdelone.o ft_lstdel.o ft_lstadd.o ft_lstiter.o ft_lstmap.o ft_sqrt.o ft_recursive_factorial.o ft_swap.o ft_is_prime.o ft_isspace.o get_next_line.o
HEADER_LIBFT = -I libft/includes -I includes

.PHONY: all clean fclean re

all: $(NAME)
$(NAME): $(C_FILES)
	@echo "\033[0;36mBuild $(NAME)"
	@make -C libft/
	@gcc -c $(FLAGS) $(C_FILES) $(HEADER_LIBFT)
	@ar rc $(NAME) $(O_FILES) $(addprefix 'libft/', $(SRCS_LIBFT))
	@ranlib $(NAME)
clean:
	@echo "\033[0;36mDelete printf object files"
	@rm -rf $(O_FILES)
	@make -C libft/ clean
fclean: clean
	@echo "\033[0;36mDelete $(NAME)"
	@rm -rf $(NAME)
	@make -C libft/ fclean
re: fclean all
