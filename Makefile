# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: opariy <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/13 13:07:08 by opariy            #+#    #+#              #
#    Updated: 2017/07/23 16:03:00 by opariy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SOURCE = ft_printf.c ft_set_func_array.c ft_parse_spec.c ft_parse_instruction.c set_of_functions.c ft_itoa_base.c ft_set_func_array.c parse_s_c.c w_char_str.c parse_u_o.c parse_x_b.c parse_d_i.c parse_width.c parse_width_prec.c put_str.c
OBJ = $(SOURCE:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ) libft/libft.a
	@ar -rc $(NAME) libft/*.o $(OBJ)

.c.o:
	gcc -Wall -Wextra -Werror -c -o $@ $<

libft/libft.a:
	make -C libft

clean:
	rm -f $(OBJ)
	make -C libft fclean

fclean: clean
	rm -f $(NAME)

re: fclean all
