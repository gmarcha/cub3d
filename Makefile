NAME		=	cub3d
CC			=	gcc
FLAGS		=	-Wall -Wextra -Werror
INC			=	-I ./inc
LIB			=	-L ./libft -lft -lmlx -lXext -lX11 -lm -lbsd
OBJ			=	$(patsubst src%, obj%, $(SRC:.c=.o))
SRC			=	src/check_info.c \
				src/check_map.c \
				src/cub3d.c \
				src/destroy.c \
				src/draw_env.c \
				src/fill_map.c \
				src/init_map.c \
				src/init_scene.c \
				src/init.c \
				src/mlx_utils.c \
				src/parse_color.c \
				src/parse_info.c \
				src/parse_map.c \
				src/parse_resolution.c \
				src/parse_scene.c \
				src/parse_texture.c \
				src/parse_value.c \
				src/parse_wall.c \
				src/ray_casting.c \
				src/ray_core.c \
				src/ray_dist.c \
				src/ray_init.c \
				src/ray_texture.c \
				src/root_init.c \
				src/size_map.c \
				src/utils.c \
				src/valid_map.c

all:		$(NAME)

$(NAME):	$(OBJ)
			make -C libft
			$(CC) $(FLAGS) -fsanitize=address -o $@ $^ $(LIB)

obj/%.o:	src/%.c
			$(CC) $(FLAGS) $(INC) -o $@ -c $<

norm:
			norminette inc/cub3d.h $(SRC)

run:		$(NAME)
			./$(NAME) map.cub

clean:
			make $@ -C libft
			rm -rf $(OBJ)

fclean:		clean
			make $@ -C libft
			rm -rf $(NAME)

re:			fclean all

.PHONY:		all norm run clean fclean re
