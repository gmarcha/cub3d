#include "cub3d.h"

void	free_root(t_root *root)
{
	int				i;

	if (root->map)
		free_matrix(root->map, root->nb_lines + 2);
	i = -1;
	while (++i < 4)
		if (root->walls_texture[i])
			mlx_destroy_image(root->mlx, root->walls_texture[i]);
	if (root->mlx)
		mlx_destroy_display(root->mlx);
	free(root);
}
