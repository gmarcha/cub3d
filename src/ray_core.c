#include "cub3d.h"

t_ray	*ray_core(t_root *root, int i)
{
	t_ray			*ray;

	ray = ray_init(root, i);
	if (ray == 0)
		return (0);
	if (ray->card % 2)
		ray->wall_dist = (ray->pos_x - root->pos_x + (1 - ray->ext_x) / 2) / ray->dir_x;
	else
		ray->wall_dist = (ray->pos_y - root->pos_y + (1 - ray->ext_y) / 2) / ray->dir_y;
	// printf("%f\t%f\n", root->pos_x, root->pos_y);
	// printf("%f\n", ray->wall_dist);
	ray->wall_height = (int)(root->height / ray->wall_dist);
	// printf("%d\n", ray->wall_height);
	ray->wall_start = -ray->wall_height / 2 + root->height / 2;
	if (ray->wall_start < 0)
		ray->wall_start = 0;
	ray->wall_end = ray->wall_height / 2 + root->height / 2;
	if (ray->wall_end >= root->height)
		ray->wall_end = root->height - 1;
	// printf("%d\t%d\n", ray->wall_start, ray->wall_end);
	return (ray_texture(root, ray));
}
