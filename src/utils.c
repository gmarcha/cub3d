#include "cub3d.h"

int	ft_strclen(char *s, int c)
{
	int			i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

int	is_space(int c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

int	**allocate_map(int nb_lines, int size_line)
{
	int				**map;
	int				i;

	map = (int **)malloc(sizeof(int *) * nb_lines);
	if (map == 0)
		return (0);
	i = 0;
	while (i < nb_lines)
	{
		map[i] = (int *)malloc(sizeof(int) * size_line);
		if (map[i] == 0)
			return (free_matrix(map, i));
		i++;
	}
	return (map);
}

t_sprite	*allocate_sprites(int nb_sprites)
{
	t_sprite		*sprites;

	sprites = (t_sprite *)malloc(sizeof(t_sprite) * nb_sprites);
	if (sprites == 0)
		return (0);
	return (sprites);
}

void	print_map(int **map, int nb_lines, int size_line)
{
	int				i;
	int				j;

	i = 0;
	while (i < nb_lines + 1)
	{
		j = 0;
		while (j < size_line + 1)
		{
			if (map[i][j] == 1)
				printf("X");
			else if (map[i][j] == -1)
				printf("-");
			else if (map[i][j] == 0)
				printf(" ");
			else if (map[i][j] == 2)
				printf("O");
			else
				printf("?");
			j++;
		}
		printf("\n");
		i++;
	}
	printf("\n============================================================\n");
}
