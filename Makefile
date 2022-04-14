# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmyriah <gmyriah@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/13 13:05:03 by gmyriah           #+#    #+#              #
#    Updated: 2022/04/13 13:05:10 by gmyriah          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

INCLUDES = includes
HEADER = $(INCLUDES)/so_long.h

DIR_S		= source/
DIR_O		= objects/
C_FILES		= game_utils.c get_next_line.c image.c map_parse.c map_validate.c so_long.c
SRCS = $(addprefix $(DIR_S),$(C_FILES))
OBJS = $(addprefix $(DIR_O),$(C_FILES:.c=.o))

#libft
LIBFT_DIR = libft
LIBFT_INCLUDES = $(LIBFT_DIR)/includes
LIBFT_HEADER = $(LIBFT_INCLUDES)/libft.h
LIBFT = $(LIBFT_DIR)/libft.a

#MLX
MLX_DIR	= mlx
MLX	= $(MLX_DIR)/libmlx.a

#flags
CC = cc
CFLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -L minilibx_opengl_20191021 -framework OpenGL -framework AppKit

.PHONY: all libft clean fclean re

all: mlx libft $(DIR_O) $(NAME)

libft:
	make -C $(LIBFT_DIR)

mlx:
	make -C $(MLX_DIR)

$(NAME): $(OBJS)
	make -C $(MLX_DIR)
	$(CC) $(CFLAGS) $(MLX_FLAGS) $(OBJS) $(LIBFT) $(MLX) -o $@

$(DIR_O)%.o: $(DIR_S)%.c $(LIBFT) $(HEADER)
	$(CC) $(CFLAGS) -I $(INCLUDES) -I $(LIBFT_INCLUDES) -I $(MLX_DIR) -c $< -o $@

$(DIR_O):
	mkdir -p $(DIR_O)

clean:
	rm -rf $(DIR_O)
	make -C $(LIBFT_DIR) clean
	make -C $(MLX_DIR) clean

fclean:	clean
	rm -r $(NAME)
	make -C $(LIBFT_DIR) fclean

re:	fclean all
