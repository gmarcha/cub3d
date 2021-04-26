#include "cub3d.h"

void	mlx_draw_pixel(t_img *mlx_img, int x, int y, int color)
{
	char			*target;

	printf("%d\n", mlx_img->bpp / 8);
	target = mlx_img->data + (x * (mlx_img->bpp / 8) + y * mlx_img->size_line);
	*(unsigned int *)target = color;
}

int	mlx_rgb_to_int(int o, int r, int g, int b)
{
	return (o << 24 | r << 16 | g << 8 | b);
}
