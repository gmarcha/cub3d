#include "cub3d.h"

t_root	*valid_map(t_root *root, int **map)
{
	int				i;
	int				j;

	i = 0;
	while (++i < root->nb_lines + 1)
	{
		j = 0;
		while (++j < root->size_line + 1)
		{
			if (map[i][j] == 0)
				if (map[i - 1][j] == -1 || map[i + 1][j] == -1
				|| map[i][j - 1] == -1 || map[i][j + 1] == -1)
					return (destroy(root, 2, "error: invalid map"));
			if (map[i][j] == -1)
				if (map[i - 1][j] == 0 || map[i + 1][j] == 0
				|| map[i][j - 1] == 0 || map[i][j + 1] == 0)
					return (destroy(root, 2, "error: invalid map"));
		}
	}
	return (root);
}
