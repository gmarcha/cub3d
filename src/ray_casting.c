#include "cub3d.h"

t_ray	*ray_casting(t_root *root, t_ray *ray)
{
	while (1)
	{
		if (ray->dist_to_x < ray->dist_to_y)
		{
			ray->dist_to_x += ray->dist_from_x;
			ray->pos_x += ray->ext_x;
			ray->card = 1;
			if (ray->ext_x == 1)
				ray->card = 3;
		}
		else
		{
			ray->dist_to_y += ray->dist_from_y;
			ray->pos_y += ray->ext_y;
			ray->card = 0;
			if (ray->ext_y == 1)
				ray->card = 2;
		}
		if (root->map[ray->pos_x][ray->pos_y] == 1)
			return (ray);
	}
	return (0);
}
