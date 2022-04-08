NAME_SL		= so_long

NAME_SLB	= so_long_bonus

LIB_DIR		= libft

LIBFT		= $(LIB_DIR)/libft.a

INCLUDES_SL	= includes/

HEADER_SL	= includes/so_long.h

HEADER_SLB	= includes/so_long_bonus.h

DIR_SL		= srcs/

DIR_SLB		= bonus/

FILES_SL	= game_utils.c\
 				get_next_line.c\
 				image.c\
 				map_parse.c\
 				map_validate.c\
 				so_long.c\		

SRCS_SL		= $(addprefix $(DIR_SL), $(FILES_SL))

SRCS_SLB	= $(addprefix $(DIR_SLB), $(FILES_SLB))

OBJS_SL		= $(SRCS_SL:%.c=%.o)

OBJS_SLB	= $(SRCS_SLB:%.c=%.o)

CC 			= cc

CFLAGS		= -Wall -Wextra -Werror

MLX_FLAGS = -L minilibx_opengl_20191021 -framework OpenGL -framework AppKit

.PHONY: 	all libft mlx clean fclean re bonus

all:		libft $(NAME_SL)

libft:
			make -C $(LIB_DIR)

bonus:
			@make NAME_SL="$(NAME_SLB)" \
			OBJS_SL="$(OBJS_SLB)" \
			HEADER_SL="$(HEADER_SLB)" all

$(NAME_SL):	$(OBJS_SL)
			$(CC) $(CFLAGS) $(MLX_FLAGS) $(OBJS_SL) $(LIBFT) minilibx_opengl_20191021/libmlx.a -o $@

%.o:		%.c $(LIBFT) $(HEADER_SL) 
			$(CC) $(CFLAGS) -I $(INCLUDES_SL) -I minilibx_opengl_20191021 -c $< -o $@

clean	:
			$(RM) $(OBJS_SL) $(OBJS_SLB)
			make -C $(LIB_DIR) clean
				
fclean	:	clean
			rm -r $(NAME_SL) $(NAME_SLB)
			make -C $(LIB_DIR) fclean

re		:	fclean all