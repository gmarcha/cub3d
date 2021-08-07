#include "cub3d.h"

void	move_up(t_root *root)
{
	if (root->map[(int)(root->pos_x + root->dir_x) * MOVE_SPEED][(int)root->pos_y] != 1)
		root->pos_x += root->dir_x * MOVE_SPEED / 10;
	if (root->map[(int)root->pos_x][(int)(root->pos_y + root->dir_y) * MOVE_SPEED] != 1)
		root->pos_y += root->dir_y * MOVE_SPEED / 10;
}

void	move_down(t_root *root)
{
	if (root->map[(int)(root->pos_x - root->dir_x) * MOVE_SPEED][(int)root->pos_y] != 1)
		root->pos_x -= root->dir_x * MOVE_SPEED / 10;
	if (root->map[(int)root->pos_x][(int)(root->pos_y - root->dir_y) * MOVE_SPEED] != 1)
		root->pos_y -= root->dir_y * MOVE_SPEED / 10;
}

void	move_left(t_root *root)
{
	(void)root;
}

void	move_right(t_root *root)
{
	(void)root;
}

void	rotate_left(t_root *root)
{
	double			tmp;

	tmp = root->dir_x;
	root->dir_x = tmp * cos(ROTATION_SPEED) - root->dir_y * sin(ROTATION_SPEED);
	root->dir_y = tmp * sin(ROTATION_SPEED) + root->dir_y * cos(ROTATION_SPEED);
	tmp = root->plane_x;
	root->plane_x = tmp * cos(ROTATION_SPEED) - root->plane_y * sin(ROTATION_SPEED);
	root->plane_y = tmp * sin(ROTATION_SPEED) + root->plane_y * cos(ROTATION_SPEED);
}

void	rotate_right(t_root *root)
{
	double			tmp;

	tmp = root->dir_x;
	root->dir_x = tmp * cos(-ROTATION_SPEED) - root->dir_y * sin(-ROTATION_SPEED);
	root->dir_y = tmp * sin(-ROTATION_SPEED) + root->dir_y * cos(-ROTATION_SPEED);
	tmp = root->plane_x;
	root->plane_x = tmp * cos(-ROTATION_SPEED) - root->plane_y * sin(-ROTATION_SPEED);
	root->plane_y = tmp * sin(-ROTATION_SPEED) + root->plane_y * cos(-ROTATION_SPEED);
}

static void	update(t_root *root)
{
	if (root->move_up != 0)
		move_up(root);
	if (root->move_down != 0)
		move_down(root);
	if (root->move_left != 0)
		move_left(root);
	if (root->move_right != 0)
		move_right(root);
	if (root->rotate_left != 0)
		rotate_left(root);
	if (root->rotate_right != 0)
		rotate_right(root);
	if (draw_core(root) == 0)
		exit(1);
}

int	key_press(int keycode, t_root *root)
{
	if (keycode == 65307)
	{
		destroy(root, 4, 0);
		exit(0);
	}
	if (keycode == 119)
		root->move_up = 1;
	else if (keycode == 115)
		root->move_down = 1;
	else if (keycode == 97)
		root->move_left = 1;
	else if (keycode == 100)
		root->move_right = 1;
	else if (keycode == 65361)
		root->rotate_left = 1;
	else if (keycode == 65363)
		root->rotate_right = 1;
	update(root);
	return (1);
}

int	key_release(int keycode, t_root *root)
{
	if (keycode == 119)
		root->move_up = 0;
	else if (keycode == 115)
		root->move_down = 0;
	else if (keycode == 97)
		root->move_left = 0;
	else if (keycode == 100)
		root->move_right = 0;
	else if (keycode == 65361)
		root->rotate_left = 0;
	else if (keycode == 65363)
		root->rotate_right = 0;
	update(root);
	return (1);
}

// int	key_hook(int keycode, t_root *root)
// {
// 	double			tmp;

// 	printf("Print keycode: %d\n", keycode);
// 	if (keycode == 65307)
// 	{
// 		destroy(root, 4, 0);
// 		exit(0);
// 	}
// 	if (keycode == 119)
// 	{
// 		if (root->map[(int)(root->pos_x + root->dir_x) * MOVE_SPEED][(int)root->pos_y] != 1)
// 			root->pos_x += root->dir_x * MOVE_SPEED;
// 		if (root->map[(int)root->pos_x][(int)(root->pos_y + root->dir_y) * MOVE_SPEED] != 1)
// 			root->pos_y += root->dir_y * MOVE_SPEED;
// 	}
// 	if (keycode == 115)
// 	{
// 		if (root->map[(int)(root->pos_x - root->dir_x) * MOVE_SPEED][(int)root->pos_y] != 1)
// 			root->pos_x -= root->dir_x * MOVE_SPEED;
// 		if (root->map[(int)root->pos_x][(int)(root->pos_y - root->dir_y) * MOVE_SPEED] != 1)
// 			root->pos_y -= root->dir_y * MOVE_SPEED;
// 	}
// 	if (keycode == 65361)
// 	{
// 		tmp = root->dir_x;
// 		root->dir_x = tmp * cos(ROTATION_SPEED) - root->dir_y * sin(ROTATION_SPEED);
// 		root->dir_y = tmp * sin(ROTATION_SPEED) + root->dir_y * cos(ROTATION_SPEED);
// 		tmp = root->plane_x;
// 		root->plane_x = tmp * cos(ROTATION_SPEED) - root->plane_y * sin(ROTATION_SPEED);
// 		root->plane_y = tmp * sin(ROTATION_SPEED) + root->plane_y * cos(ROTATION_SPEED);
// 	}
// 	if (keycode == 65363)
// 	{
// 		tmp = root->dir_x;
// 		root->dir_x = tmp * cos(-ROTATION_SPEED) - root->dir_y * sin(-ROTATION_SPEED);
// 		root->dir_y = tmp * sin(-ROTATION_SPEED) + root->dir_y * cos(-ROTATION_SPEED);
// 		tmp = root->plane_x;
// 		root->plane_x = tmp * cos(-ROTATION_SPEED) - root->plane_y * sin(-ROTATION_SPEED);
// 		root->plane_y = tmp * sin(-ROTATION_SPEED) + root->plane_y * cos(-ROTATION_SPEED);
// 	}
// 	if (draw_core(root) == 0)
// 		exit(1);
// 	return (1);
// }

int	main(int argc, char *argv[])
{
	t_root			*root;

	if (argc != 2)
	{
		ft_putendl_fd("error: invalid number of arguments", 2);
		return (1);
	}
	root = init(argv[1]);
	if (root == 0)
		return (1);
	print_map(root->map, root->nb_lines + 1, root->size_line + 1);
	if (draw_core(root) == 0)
		return (1);
	// mlx_hook(root->mlx_win, 2, (1L << 0), &key_hook, root);
	mlx_hook(root->mlx_win, 2, 1L << 0, key_press, root);
	mlx_hook(root->mlx_win, 3, 1L << 1, key_release, root);
	// mlx_hook(root->mlx_win, 17, 1L << 17, destroy_hook, root);
	mlx_loop(root->mlx);
	return (0);
}
