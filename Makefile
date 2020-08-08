# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kosgrey <kosgrey@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/08 17:43:04 by kosgrey           #+#    #+#              #
#    Updated: 2020/08/08 17:43:17 by kosgrey          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=fdf
FRAEMWORKS=-framework OpenGL -framework AppKit
FLAGS=-Werror -Wextra -Wall
CC = gcc
LIBFT=Libft/libft.a
MANLIB=minilibx_macos/libmlx.a

ALL_COMPILE = additional.c \
                additional_2.c\
                draw.c \
                fdf.c \
                keybord.c \
                parcer.c \
                set_param.c \

.PHONY: re fclean clean


all:
	@make -C libft/ all
	gcc $(ALL_COMPILE) -o $(NAME) $(FLAGS) $(LIBFT) $(MANLIB) $(FRAEMWORKS)

clean:
	@make -C libft/ clean

fclean: clean
	/bin/rm -f $(NAME)
	@make -C libft/ fclean

re: fclean all
