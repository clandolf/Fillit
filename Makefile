# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hchung <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/10 03:22:34 by hchung            #+#    #+#              #
#    Updated: 2018/09/10 04:24:59 by hchung           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRCS = fillwdots.c \
	   minimize_tet.c \
	   parser.c \
	   solver.c \
	   tet_me_up.c \
	   verify_tet.c \
	   main.c \

CC = gcc
HEADER = ./libft/libft.a
CFLAGS = -Wall -Wextra -Werror
.PHONY : all clean fclean re

all : $(NAME)

$(NAME) :
	@make -C libft
	$(CC) $(CFLAGS) -o $(NAME) $(SRCS) $(HEADER)

clean :
	@make -C libft clean
	@/bin/rm -rf $(OBJ)

fclean : clean
	@make -C libft fclean
	@/bin/rm -rf $(NAME)

re : fclean all
