#include "cub3d.h"

t_root				*root_init(void)
{
	t_root			*root;
	int				i;

	root = (t_root *)malloc(sizeof(t_root));
	if (root == 0)
		return (destroy(root, 0, "error: can't allocate memory"));
	root->window_width = -1;
	root->window_height = -1;
	i = 0;
	while (i < 4)
		root->walls_texture[i++] = 0;
	root->sprite_texture = 0;
	root->floor_color = -1;
	root->ceil_color = -1;
	root->map = 0;
	root->mlx = mlx_init();
	if (root->mlx == 0)
		return (destroy(root, 2, "error: can't init mlx"));
	return (root);
}
