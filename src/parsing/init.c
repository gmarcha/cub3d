#include "cub3d.h"

t_root	*init(char *file)
{
	t_root			*r;

	r = init_scene(file);
	if (r == 0)
		return (0);
	r->mlx_win = mlx_new_window(r->mlx, r->width, r->height, "cub3d");
	if (r->mlx_win == 0)
		return (destroy(r, 2, "error: can't create a new window"));
	r->mlx_img = mlx_new_image(r->mlx, r->width, r->height);
	if (r->mlx_img == 0)
		return (destroy(r, 3, "error: can't create a new image"));
	return (r);
}
