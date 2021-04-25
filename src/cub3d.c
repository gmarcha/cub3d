#include "cub3d.h"

int					is_space(int c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

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

void				*destroy(t_root *root, int flag, char *error)
{
	if (flag > 3)
		mlx_destroy_image(root->mlx, root->mlx_img);
	if (flag > 2)
		mlx_destroy_window(root->mlx, root->mlx_win);
	if (flag > 1)
		mlx_destroy_display(root->mlx);
	if (flag > 0)
		free(root);
	if (error)
		ft_putendl_fd(error, 2);
	return (0);
}

t_root				*parse_scene(char *buf)
{
	t_root			*root;

	root = (t_root *)malloc(sizeof(t_root));
	if (root == 0)
		return (destroy(root, 0, "error: can't allocate memory"));
	while (*buf && *buf != ' ' && *buf != '1')
	{
		if (*buf == '\n')
			buf++;
		else
		{
			if (*buf == 'R')
				parse_resolution(root, &buf);
			if (*buf == 'N' && buf[1] == 'O')

			if (*buf == 'S' && buf[1] == 'O')

			if (*buf == 'W' && buf[1] == 'E')

			if (*buf == 'E' && buf[1] == 'A')

			if (*buf == 'S')

			if (*buf == 'F')

			if (*buf == 'C')

		}
	}
	return (root);
}

t_root				*init_scene(char *file)
{
	t_root			*root;
	int				fd;
	char			buf[32768 + 1];
	int				ret;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (destroy(root, 0, "error: can't open the scene (*.map)"));
	ret = read(fd, buf, 32768);
	close(fd);
	if (ret == -1)
		return (destroy(root, 0, "error: can't read the scene (*.map)"));
	if (ret == 0)
		return (destroy(root, 0, "error: scene file is empty"));
	buf[ret] = 0;
	root = parse_scene(buf);
	if (root == 0)
		return (0);
	return (root);
}

t_root				*init(char *file)
{
	t_root			*root;

	root = init_scene(file);
	if (root == 0)
		return (0);
	root->mlx = mlx_init();
	if (root->mlx == 0)
		return (destroy(root, 1, "error: can't init mlx"));
	root->mlx_win = mlx_new_window(root->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "cub3d");
	if (root->mlx_win == 0)
		return (destroy(root, 2, "error: can't create a new window"));
	root->mlx_img = mlx_new_image(root->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (root->mlx_img == 0)
		return (destroy(root, 3, "error: can't create a new image"));
	return (root);
}

int					key_hook(int keycode, t_root *root)
{
	printf("Print keycode: %d\n", keycode);
	if (keycode == 65307)
	{
		destroy(root, 4, 0);
		exit(0);
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
	mlx_put_image_to_window(root->mlx, root->mlx_win, root->mlx_img, 0, 0);
	return (1);
}

int					main(int argc, char *argv[])
{
	t_root			*root;

	if (argc != 2)
	{
		ft_putendl_fd("error: invalid number of arguments", 2);
		return (0);
	}
	root = init(argv[1]);
	if (root == 0)
		return (1);
	mlx_hook(root->mlx_win, 2, (1L<<0), &key_hook, root);
	mlx_loop(root->mlx);
	return (0);
}
