#include "cub3d.h"

t_root				*init(char *file)
{
	t_root			*root;

	root = init_scene(file);
	if (root == 0)
		return (0);
	root->mlx_win = mlx_new_window(root->mlx, root->window_width, root->window_height, "cub3d");
	if (root->mlx_win == 0)
		return (destroy(root, 2, "error: can't create a new window"));
	root->mlx_img = mlx_new_image(root->mlx, root->window_width, root->window_height);
	if (root->mlx_img == 0)
		return (destroy(root, 3, "error: can't create a new image"));
	return (root);
}
