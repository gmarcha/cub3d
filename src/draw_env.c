#include "cub3d.h"

void	draw_env(t_root *r, t_ray *ray, int i)
{
	t_img			*img;
	char			*pixel;
	int				j;

	img = r->walls_texture[ray->card];
	j = 0;
	while (j < ray->wall_start)
	{
		mlx_draw_pixel(r->mlx_img, i, j, r->ceil_color);
		mlx_draw_pixel(r->mlx_img, i, r->height - j - 1, r->floor_color);
		j++;
	}
	while (j < ray->wall_end)
	{
		ray->text_y = (int)ray->text_pos & (img->height - 1);
		ray->text_pos += ray->text_step;
		pixel = img->data + ((ray->text_x * img->bpp / 8) + (ray->text_y * img->size_line));
		mlx_draw_pixel(r->mlx_img, i, j, *(unsigned int *)pixel);
		j++;
	}
}