# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abassibe <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/01 12:45:46 by abassibe          #+#    #+#              #
#    Updated: 2017/05/15 13:58:34 by abassibe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRCS =	fdf.c \
		render.c \
		get_map.c \
		key_input.c \
		bresenham.c

OBJS = $(SRCS:.c=.o)

SRCPATH = ./srcs/

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	@gcc $(FLAGS) -c $(addprefix $(SRCPATH), $(SRCS)) \
		-I includes/
	@make -C libft
	@gcc $(FLAGS) $(OBJS) libft/libft.a -o $(NAME) \
		-L. -lmlx -framework OpenGL -framework AppKit

.PHONY: all clean fclean re

clean:
	@make -C libft clean
	@rm -rf $(OBJS)

fclean: clean
	@make -C libft fclean
	@rm -rf libft/libft.a $(NAME)

re: fclean all

