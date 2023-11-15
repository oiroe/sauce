# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pboonpro <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/06 15:27:44 by pboonpro          #+#    #+#              #
#    Updated: 2023/11/15 00:46:54 by pboonpro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = sort

SRC = time.c meaw.c simple_sort.c

OBJ = $(SRC:%.c=%.o)

LIBFT = libft/libft.a

CC = cc

CFLAGS = -Wall -Wextra -Werror -g

all : $(NAME)

$(NAME) : $(OBJ)
	make -C ./libft
	$(CC) $(CFLAGS) $^ $(LIBFT) -o $@

clean :
	make clean -C libft
	rm -rf $(OBJ)

fclean : clean
	make fclean -C libft
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re
