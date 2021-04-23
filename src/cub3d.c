#include "cub3d.h"

void				mlx_draw_pixel(t_img *mlx_img, int x, int y, int color)
{
	char			*target;

	target = mlx_img->data + (x * (mlx_img->bpp / 8) + y * mlx_img->size_line);
	*(unsigned int *)target = color;
}

void				draw_square(t_img *img, int color)
{
	for (int i = 0; i < WINDOW_WIDTH; i++)
		for (int j = 0; j < WINDOW_HEIGHT; j++)
			mlx_draw_pixel(img, i, j, color);
}

int					key_hook(int keycode, t_root *root)
{
	printf("Print keycode: %d\n", keycode);
	if (keycode == 65307)
	{
		mlx_destroy_window(root->mlx, root->mlx_win);
		return (0);
	}
	draw_square(root->mlx_img, 0x00000000);
	if (keycode == 65361)
		draw_square(root->mlx_img, 0x00FF0000);
	if (keycode == 65362)
		draw_square(root->mlx_img, 0x0000FF00);
	if (keycode == 65363)
		draw_square(root->mlx_img, 0x000000FF);
	if (keycode == 65364)
		draw_square(root->mlx_img, 0x00FFFFFF);
	return (1);
}

int					main(void)
{
	t_root			*root;

	root = (t_root *)malloc(sizeof(t_root));
	if (root == 0)
	{
		ft_putendl_fd("error: can't allocate memory", 2);
		return (1);
	}
	root->mlx = mlx_init();
	if (root->mlx == 0)
	{
		ft_putendl_fd("error: can't init mlx", 2);
		return (1);
	}
	root->mlx_win = mlx_new_window(root->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "cub3d");
	if (root->mlx_win == 0)
	{
		ft_putendl_fd("error: can't create a new window", 2);
		return (1);
	}
	root->mlx_img = mlx_new_image(root->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (root->mlx_img == 0)
	{
		ft_putendl_fd("error: can't create a new image", 2);
		return (1);
	}
	mlx_put_image_to_window(root->mlx, root->mlx_win, root->mlx_img, 0, 0);
	mlx_hook(root->mlx_win, 2, (1L<<0), &key_hook, root);
	mlx_loop(root->mlx);
	return (0);
}
