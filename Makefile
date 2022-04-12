NAME		= so_long

LIBFT_DIR	= libft

LIBFT		= $(LIBFT_DIR)/libft.a

INCLUDES	= includes/

HEADER		= includes/so_long.h

DIR_S		= source/

C_FILES		= game_utils.c get_next_line.c image.c map_parse.c map_validate.c so_long.c

SRCS		= $(addprefix $(DIR_S), $(C_FILES))

OBJS		= $(SRCS:%.c=%.o)

CC 			= cc

CFLAGS		= -Wall -Wextra -Werror

MLX_FLAGS	= -L minilibx_opengl_20191021 -framework OpenGL -framework AppKit

.PHONY: 	all libft mlx clean fclean re

all:		libft $(NAME)

libft:
			make -C $(LIBFT_DIR)

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) $(MLX_FLAGS) $(OBJS) $(LIBFT) minilibx_opengl_20191021/libmlx.a -o $@

%.o:	%.c $(LIBFT) $(HEADER)
			$(CC) $(CFLAGS) -I $(INCLUDES) -I minilibx_opengl_20191021 -c $< -o $@

clean	:
			$(RM) $(OBJS)
			make -C $(LIBFT_DIR) clean
				
fclean	:	clean
			rm -r $(NAME)
			make -C $(LIBFT_DIR) fclean

re		:	fclean all
