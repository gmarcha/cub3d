NAME		= cub3d
CC			= gcc
FLAGS		= -Wall -Wextra -Werror
INC			= -I ./inc
LIB			= -L ./libft -lft -lmlx -lXext -lX11 -lm -lbsd
OBJ			= $(patsubst src%, obj%, $(SRC:.c=.o))
SRC			= src/cub3d.c

all:		$(NAME)

$(NAME):	$(OBJ)
			make -C libft
			$(CC) $(FLAGS) -fsanitize=address -o $@ $^ $(LIB)

obj/%.o:	src/%.c
			$(CC) $(FLAGS) $(INC) -o $@ -c $<

norm:
			norminette $(SRC)

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
