#include "cub3d.h"

t_root	*draw_core(t_root *root)
{
	t_ray			*ray;
	double			*buf;
	int				i;

	buf = (double *)malloc(sizeof(double) * root->width);
	if (buf == 0)
		return (destroy(root, 4, "error: can't allocate zbuffer"));
	i = 0;
	while (i < root->width)
	{
		ray = ray_core(root, i);
		if (ray == 0)
		{
			free(buf);
			return (destroy(root, 4, "error: can't init ray"));
		}
		buf[i] = ray->wall_dist;
		draw_env(root, ray, i);
		free(ray);
		i++;
	}

	free(buf);
	mlx_put_image_to_window(root->mlx, root->mlx_win, root->mlx_img, 0, 0);
	return (root);
}

int	key_hook(int keycode, t_root *r)
{
	double			tmp;

	printf("Print keycode: %d\n", keycode);
	if (keycode == 65307)
	{
		destroy(r, 4, 0);
		exit(0);
	}
	if (keycode == 119)
	{
		if (r->map[(int)(r->pos_x + r->dir_x * MS)][(int)r->pos_y] != 1)
			r->pos_x += r->dir_x * MS;
		if (r->map[(int)r->pos_x][(int)(r->pos_y + r->dir_y * MS)] != 1)
			r->pos_y += r->dir_y * MS;
	}
	if (keycode == 115)
	{
		if (r->map[(int)(r->pos_x - r->dir_x * MS)][(int)r->pos_y] != 1)
			r->pos_x -= r->dir_x * MS;
		if (r->map[(int)r->pos_x][(int)(r->pos_y - r->dir_y * MS)] != 1)
			r->pos_y -= r->dir_y * MS;
	}
	if (keycode == 65361)
	{
		tmp = r->dir_x;
		r->dir_x = tmp * cos(RS) - r->dir_y * sin(RS);
		r->dir_y = tmp * sin(RS) + r->dir_y * cos(RS);
		tmp = r->plane_x;
		r->plane_x = tmp * cos(RS) - r->plane_y * sin(RS);
		r->plane_y = tmp * sin(RS) + r->plane_y * cos(RS);
	}
	if (keycode == 65363)
	{
		tmp = r->dir_x;
		r->dir_x = tmp * cos(-RS) - r->dir_y * sin(-RS);
		r->dir_y = tmp * sin(-RS) + r->dir_y * cos(-RS);
		tmp = r->plane_x;
		r->plane_x = tmp * cos(-RS) - r->plane_y * sin(-RS);
		r->plane_y = tmp * sin(-RS) + r->plane_y * cos(-RS);
	}
	if (draw_core(r) == 0)
	{
		destroy(r, 4, 0);
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
