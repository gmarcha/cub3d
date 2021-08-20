NAME		=	cub3d
LFT			=	libft/libft.a
MLX			=	mlx/libmlx.a
CC			=	clang
CFLAGS		=	-Wall -Wextra -Werror -O3
INC			=	-I ./inc -I ./libft -I ./mlx
LIB			=	-L ./libft -lft -L ./mlx -lmlx -lXext -lX11 -lm -lbsd
OBJ			=	$(patsubst src%, obj%, $(SRC:.c=.o))
SRC			=	src/draw/draw_core.c \
				src/draw/draw_env.c \
				src/engine/loop_routine.c \
				src/engine/update.c \
				src/event/key_press.c \
				src/event/key_release.c \
				src/event/move_down.c \
				src/event/move_left.c \
				src/event/move_right.c \
				src/event/move_up.c \
				src/event/rotate_left.c \
				src/event/rotate_right.c \
				src/input/check_info.c \
				src/input/check_map.c \
				src/input/fill_map.c \
				src/input/init_map.c \
				src/input/init_scene.c \
				src/input/init.c \
				src/input/parse_color.c \
				src/input/parse_info.c \
				src/input/parse_map.c \
				src/input/parse_scene.c \
				src/input/parse_texture.c \
				src/input/parse_value.c \
				src/input/parse_wall.c \
				src/input/root_init.c \
				src/input/size_map.c \
				src/input/valid_map.c \
				src/ray/ray_casting.c \
				src/ray/ray_core.c \
				src/ray/ray_dist.c \
				src/ray/ray_init.c \
				src/ray/ray_texture.c \
				src/utils/allocate_map.c \
				src/utils/destroy.c \
				src/utils/free_matrix.c \
				src/utils/free_root.c \
				src/utils/mlx_draw_pixel.c \
				src/utils/mlx_rgb_to_int.c \
				src/cub3d.c
CLR			=	"\\033[2K"

all:		obj $(NAME)

$(NAME):	$(MLX) $(LFT) $(OBJ)
			@echo "$(CLR)$(NAME): compilation done"
			@echo "$(NAME): linking object files\r\c"
			@$(CC) $(CFLAGS) -o $@ $^ $(LIB)
			@echo "$(CLR)$(NAME): link done"

$(LFT):
			@echo "libft: creating library\r\c"
			@make -s -C libft
			@echo "$(CLR)libft: library created"

$(MLX):
			@echo "minilibx: creating library $<\r\c"
			@make -s -C mlx
			@echo "$(CLR)minilibx: library created"

obj/%.o:	src/%.c
			@echo "$(CLR)$(NAME): compiling $<\r\c"
			@$(CC) $(CFLAGS) $(INC) -o $@ -c $<

obj:
			@mkdir -p obj
			@mkdir -p obj/draw
			@mkdir -p obj/engine
			@mkdir -p obj/event
			@mkdir -p obj/input
			@mkdir -p obj/ray
			@mkdir -p obj/utils

test:		all
			@bash test/test_invalid.sh

clean:
			@[ ! -e mlx/Makefile.gen ] || make -s $@ -C mlx
			@make -s $@ -C libft
			@rm -rf $(OBJ) obj
			@echo "$@: object files removed"

fclean:		clean
			@make -s $@ -C libft
			@rm -rf $(NAME)
			@echo "$@: binary file removed"

re:			fclean all

.PHONY:		all obj test clean fclean re
