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