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

void	print_map(int **map, int nb_lines, int size_line)
{
	int				i;
	int				j;

	i = 0;
	while (++i < nb_lines)
	{
		j = 0;
		while (++j < size_line)
		{
			if (map[i][j] == 1)
				printf("X");
			else
				printf(" ");
		}
		printf("\n");
	}
	printf("\n============================================================\n");
}

void	draw_square(t_img *img, int color)
{
	int				i;
	int				j;

	i = 0;
	while (i < 640)
	{
		j = 0;
		while (j < 480)
			mlx_draw_pixel(img, i, j++, color);
		i++;
	}
}
