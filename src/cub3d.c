#include "cub3d.h"

t_root				*parse_wall(t_root *root, char **buf)
{
	(*buf) += 2;
	if (**buf == 'N' && (*buf)[1] == 'O')
		if (parse_texture(root, buf, &root->walls_texture[0]) == 0)
			return (0);
	if (**buf == 'S' && (*buf)[1] == 'O')
		if (parse_texture(root, buf, &root->walls_texture[2]) == 0)
			return (0);
	if (**buf == 'W' && (*buf)[1] == 'E')
		if (parse_texture(root, buf, &root->walls_texture[1]) == 0)
			return (0);
	if (**buf == 'E' && (*buf)[1] == 'A')
		if (parse_texture(root, buf, &root->walls_texture[3]) == 0)
			return (0);
	return (root);
}

t_root				*parse_info(t_root *root, char **buf)
{
	if ((**buf == 'N' && (*buf)[1] == 'O') || (**buf == 'S' && (*buf)[1] == 'O')
	|| (**buf == 'W' && (*buf)[1] == 'E') || (**buf == 'E' && (*buf)[1] == 'A'))
		if (parse_wall(root, buf) == 0)
			return (0);
	if (**buf == 'R' || **buf == 'S' || **buf == 'F' || **buf == 'C')
	{
		(*buf)++;
		if (**buf == 'R')
			if (parse_resolution(root, buf) == 0)
				return (0);
		if (**buf == 'S')
			if (parse_texture(root, buf, &root->sprite_texture) == 0)
				return (0);
		if (**buf == 'F')
			if (parse_color(root, buf, &root->floor_color) == 0)
				return (0);
		if (**buf == 'C')
			if (parse_color(root, buf, &root->ceil_color) == 0)
				return (0);
		return (root);
	}
	return (destroy(root, 2, "error: wrong identifier"));
}

t_root				*check_info(t_root *root)
{
	int				i;

	if (root->window_width == -1 || root->window_height == -1)
		return (destroy(root, 2, "error: resolution is missing"));
	i = 0;
	while (i < 4)
		if (root->walls_texture[i++] == 0 || root->sprite_texture == 0)
			return (destroy(root, 2, "error: texture is missing"));
	if (root->floor_color == -1 || root->ceil_color == -1)
		return (destroy(root, 2, "error: floor or ceil color is missing"));
	return (root);
}

t_root				*parse_scene(char *buf)
{
	t_root			*root;

	root = root_init();
	if (root == 0)
		return (0);
	while (*buf && *buf != ' ' && *buf != '1')
	{
		if (*buf == '\n')
			buf++;
		else
			if (parse_info(root, &buf) == 0)
				return (0);
	}
	if (check_info(root) == 0)
		return (0);
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
