#include "cub3d.h"

void				mlx_draw_pixel(t_img *mlx_img, int x, int y, int color)
{
	char			*target;

	target = mlx_img->data + (x * (mlx_img->bpp / 8) + y * mlx_img->size_line);
	*(unsigned int *)target = color;
}

int					key_hook(int keycode, t_img *mlx_img)
{
	printf("Hello World!\n");
}

int					main(void)
{
	void			*mlx;
	void			*mlx_win;
	void			*mlx_img;

	mlx = mlx_init();
	if (mlx == 0)
	{
		ft_putendl_fd("error: can't init mlx", 2);
		return (1);
	}
	mlx_win = mlx_new_window(mlx, 640, 480, "cub3d");
	if (mlx_win == 0)
	{
		ft_putendl_fd("error: can't create a new window", 2);
		return (1);
	}
	mlx_img = mlx_new_image(mlx, 640, 480);
	if (mlx_img == 0)
	{
		ft_putendl_fd("error: can't create a new image", 2);
		return (1);
	}

	for (int i = 0; i < 200; i++)
		for (int j = 0; j < 200; j++)
			mlx_draw_pixel(mlx_img, i, j, 0x00FF0000);
	mlx_put_image_to_window(mlx, mlx_win, mlx_img, 0, 0);
	mlx_key_hook(vars.win, &key_hook, mlx_img);

	ft_putendl_fd("Hello World!", 1);
	mlx_loop(mlx);
	return (0);
}
