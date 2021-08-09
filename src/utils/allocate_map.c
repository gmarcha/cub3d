#include "cub3d.h"

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
