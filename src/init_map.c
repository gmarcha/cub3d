#include "cub3d.h"

int	**init_map(t_root *root, char *buf)
{
	int				**map;

	root->nb_sprites = 0;
	root->nb_lines = 1;
	root->size_line = 0;
	if (size_map(root, buf) == 0)
		return (0);
	if (root->nb_lines < 3 || root->size_line < 3)
		return (destroy(root, 2, "error: map is too little"));
	map = allocate_map(root->nb_lines + 2, root->size_line + 2);
	if (map == 0)
		return (destroy(root, 2, "error: can't allocate memory"));
	root->sprites = allocate_sprites(root->nb_sprites);
	if (root->sprites == 0)
	{
		free_matrix(map, root->nb_lines + 2);
		return (destroy(root, 2, "error: can't allocate memory"));
	}
	return (map);
}
