NAME		=	cub3d
LFT			=	libft/libft.a
MLX			=	mlx/Makefile.gen
CC			=	clang
FLAGS		=	-Wall -Wextra -Werror
INC			=	-I ./inc -I ./libft -I ./mlx
LIB			=	-L ./libft -lft -L ./mlx -lmlx -lXext -lX11 -lm -lbsd
OBJ			=	$(patsubst src%, obj%, $(SRC:.c=.o))
SRC			=	src/draw/draw_core.c \
				src/draw/draw_env.c \
				src/parsing/check_info.c \
				src/parsing/check_map.c \
				src/parsing/fill_map.c \
				src/parsing/init_map.c \
				src/parsing/init_scene.c \
				src/parsing/init.c \
				src/parsing/parse_color.c \
				src/parsing/parse_info.c \
				src/parsing/parse_map.c \
				src/parsing/parse_resolution.c \
				src/parsing/parse_scene.c \
				src/parsing/parse_texture.c \
				src/parsing/parse_value.c \
				src/parsing/parse_wall.c \
				src/parsing/root_init.c \
				src/parsing/size_map.c \
				src/parsing/valid_map.c \
				src/ray/ray_casting.c \
				src/ray/ray_core.c \
				src/ray/ray_dist.c \
				src/ray/ray_init.c \
				src/ray/ray_texture.c \
				src/utils/destroy.c \
				src/utils/mlx_utils.c \
				src/utils/utils.c \
				src/cub3d.c
CLR			=	"\\033[2K"

all:		$(MLX) $(LFT) obj $(NAME)

$(NAME):	$(OBJ)
			@echo "$(CLR)$(NAME): compilation done"
			@echo "$(NAME): linking object files\r\c"
			@$(CC) $(FLAGS) -fsanitize=address -o $@ $^ $(LIB)
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
			@$(CC) $(FLAGS) $(INC) -o $@ -c $<

obj:
			@mkdir -p obj
			@mkdir -p obj/draw
			@mkdir -p obj/event
			@mkdir -p obj/parsing
			@mkdir -p obj/ray
			@mkdir -p obj/utils

clean:
			@make -s $@ -C libft
			@rm -rf $(OBJ) obj
			@echo "$@: object files removed"

fclean:		clean
			@make -s $@ -C libft
			@rm -rf $(NAME)
			@echo "$@: binary file removed"

re:			fclean all

.PHONY:		all obj clean fclean re
