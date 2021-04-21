NAME		= cub3d
CC			= gcc
FLAGS		= -Wall -Wextra -Werror
OBJ			= $(patsubst src%, obj%, $(SRC:.c=.o))
SRC			= src/cub3d.c

all:		$(NAME)

$(NAME):	$(OBJ)
			$(CC) $(FLAGS) -o $@ $^ $(LIBS)

obj/%.o:	src/%.c $(HEAD)
			$(CC) $(FLAGS) -o $@ -c $<

norm:
			norminette $(SRC)

run:		$(NAME)
			./$(NAME) map.cub

clean:
			rm -rf $(OBJ)

fclean:		clean
			rm -rf $(NAME)

re:			fclean all

.PHONY:		all norm run clean fclean re
