NAME		= cub3d
CC			= gcc
FLAGS		= -Wall -Wextra -Werror
INC			= -I ./inc -I /usr/include/sys -I /usr/include/X11 -I /usr/include/X11/extensions
LIB			= -L ./libft -lft -L ./minilibx -lmlx -L /usr/lib -lm -lX11 -lXext -lbsd
OBJ			= $(patsubst src%, obj%, $(SRC:.c=.o))
SRC			= src/cub3d.c

all:		$(NAME)

$(NAME):	$(OBJ)
			make -C libft
			make -C minilibx
			$(CC) $(FLAGS) -o $@ $^ $(LIB)

obj/%.o:	src/%.c
			$(CC) $(FLAGS) $(INC) -o $@ -c $<

norm:
			norminette $(SRC)

run:		$(NAME)
			./$(NAME) map.cub

clean:
			make $@ -C libft
			make $@ -C minilibx
			rm -rf $(OBJ)

fclean:		clean
			make $@ -C libft
			rm -rf $(NAME)

re:			fclean all

.PHONY:		all norm run clean fclean re
