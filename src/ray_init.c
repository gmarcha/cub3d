#include "cub3d.h"

t_ray	*ray_init(t_root *root, int i)
{
	t_ray			*ray;
	double			dir;

	ray = (t_ray *)malloc(sizeof(t_ray));
	if (ray == 0)
		return (0);
	dir = i * 2 / (double)(root->width) - 1;
	ray->pos_x = (int)root->pos_x;
	ray->pos_y = (int)root->pos_y;
	ray->dir_x = root->dir_x + root->plane_x * dir;
	ray->dir_y = root->dir_y + root->plane_y * dir;
	if (ray->dir_x < 0)
		ray->ext_x = -1;
	else
		ray->ext_x = 1;
	if (ray->dir_y < 0)
		ray->ext_y = -1;
	else
		ray->ext_y = 1;
	// printf("%d\t%d\n", ray->pos_x, ray->pos_y);
	// printf("%f\t%f\n", ray->dir_x, ray->dir_y);
	return (ray_dist(root, ray));
}
