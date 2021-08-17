#include "cub3d.h"

t_root	*check_info(t_root *root)
{
	int				i;

	i = 0;
	while (i < 4)
		if (root->walls_texture[i++] == 0)
			return (destroy(root, 2, "error: texture is missing"));
	if (root->floor_color == -1 || root->ceil_color == -1)
		return (destroy(root, 2, "error: floor or ceil color is missing"));
	return (root);
}
