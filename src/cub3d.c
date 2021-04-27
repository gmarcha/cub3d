#include "cub3d.h"

t_root	*draw_core(t_root *root)
{
	t_ray			*ray;
	int				i;

	i = 0;
	while (i < root->width)
	{
		ray = ray_core(root, i);
		if (ray == 0)
			return (destroy(root, 4, "error: can't draw"));
		draw_env(root, ray, i);
		free(ray);
		i++;
	}
	mlx_put_image_to_window(root->mlx, root->mlx_win, root->mlx_img, 0, 0);
	return (root);
}

int	key_hook(int keycode, t_root *root)
{
	double			tmp;

	printf("Print keycode: %d\n", keycode);
	if (keycode == 65307)
	{
		destroy(root, 4, 0);
		exit(0);
	}
	if (keycode == 119)
	{
		if (root->map[(int)(root->pos_x + root->dir_x) * MOVE_SPEED][(int)root->pos_y] != 1)
			root->pos_x += root->dir_x * MOVE_SPEED;
		if (root->map[(int)root->pos_x][(int)(root->pos_y + root->dir_y) * MOVE_SPEED] != 1)
			root->pos_y += root->dir_y * MOVE_SPEED;
	}
	if (keycode == 115)
	{
		if (root->map[(int)(root->pos_x - root->dir_x) * MOVE_SPEED][(int)root->pos_y] != 1)
			root->pos_x -= root->dir_x * MOVE_SPEED;
		if (root->map[(int)root->pos_x][(int)(root->pos_y - root->dir_y) * MOVE_SPEED] != 1)
			root->pos_y -= root->dir_y * MOVE_SPEED;
	}
	// if (keycode == 97) {};
	// if (keycode == 100) {};
	if (keycode == 65361)
	{
		tmp = root->dir_x;
		root->dir_x = tmp * cos(ROTATION_SPEED) - root->dir_y * sin(ROTATION_SPEED);
		root->dir_y = tmp * sin(ROTATION_SPEED) + root->dir_y * cos(ROTATION_SPEED);
		tmp = root->plane_x;
		root->plane_x = tmp * cos(ROTATION_SPEED) - root->plane_y * sin(ROTATION_SPEED);
		root->plane_y = tmp * sin(ROTATION_SPEED) + root->plane_y * cos(ROTATION_SPEED);
	}
	if (keycode == 65363)
	{
		tmp = root->dir_x;
		root->dir_x = tmp * cos(-ROTATION_SPEED) - root->dir_y * sin(-ROTATION_SPEED);
		root->dir_y = tmp * sin(-ROTATION_SPEED) + root->dir_y * cos(-ROTATION_SPEED);
		tmp = root->plane_x;
		root->plane_x = tmp * cos(-ROTATION_SPEED) - root->plane_y * sin(-ROTATION_SPEED);
		root->plane_y = tmp * sin(-ROTATION_SPEED) + root->plane_y * cos(-ROTATION_SPEED);
	}
	if (draw_core(root) == 0)
	{
		destroy(root, 4, 0);
		exit(0);
	}
	return (1);
}

int	main(int argc, char *argv[])
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
	print_map(root->map, root->nb_lines + 1, root->size_line + 1);
	if (draw_core(root) == 0)
	{
		destroy(root, 4, 0);
		exit(0);
	}
	mlx_hook(root->mlx_win, 2, (1L << 0), &key_hook, root);
	mlx_loop(root->mlx);
	return (0);
}
