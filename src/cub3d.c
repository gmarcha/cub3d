#include "cub3d.h"

t_ray	*ray_casting(t_root *root, t_ray *ray)
{
	while (root->map[ray->pos_x][ray->pos_y] != 1)
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
	}
	return (ray);
}

t_ray	*ray_dist(t_root *root, t_ray *ray)
{
	ray->dist_from_x = 1 / ray->dir_x;
	if (ray->dist_from_x < 0)
		ray->dist_from_x *= -1;
	ray->dist_from_y = 1 / ray->dir_y;
	if (ray->dist_from_y < 0)
		ray->dist_from_y *= -1;
	if (ray->dir_x < 0)
		ray->dist_to_x = (root->pos_x - ray->pos_x) * ray->dist_from_x;
	else
		ray->dist_to_x = (ray->pos_x + 1 - root->pos_x) * ray->dist_from_x;
	if (ray->dir_y < 0)
		ray->dist_to_y = (root->pos_y - ray->pos_y) * ray->dist_from_y;
	else
		ray->dist_to_y = (ray->pos_y + 1 - root->pos_y) * ray->dist_from_y;
	return (ray_casting(root, ray));
}	

t_ray	*ray_init(t_root *root, int i)
{
	t_ray			*ray;
	double			dir;

	ray = (t_ray *)malloc(sizeof(t_ray));
	if (ray == 0)
		return (0);
	dir = i * 2 / (double)(root->width) - 1;
	ray->pos_x = (int)root->pos_x;
	ray->pos_y = (int)root->pos_y;
	ray->dir_x = root->dir_x + root->plane_x * dir;
	ray->dir_y = root->dir_y + root->plane_y * dir;
	if (ray->dir_x < 0)
		ray->ext_x = -1;
	else
		ray->ext_x = 1;
	if (ray->dir_y < 0)
		ray->ext_y = -1;
	else
		ray->ext_y = 1;
	return (ray_dist(root, ray));
}

t_ray	*ray_texture(t_root *root, t_ray *ray)
{
	if (ray->card % 2)
		ray->wall_coord = root->pos_y + ray->dir_y * ray->wall_dist;
	else
		ray->wall_coord = root->pos_x + ray->dir_x * ray->wall_dist;
	ray->wall_coord -= floor(ray->wall_coord);
	ray->text_x = (int)(ray->wall_coord * (double)root->walls_texture[ray->card]->width);
	if ((ray->card % 2 && ray->dir_x > 0) || (ray->card % 2 == 0 && ray->dir_y < 0))
		ray->text_x = (double)root->walls_texture[ray->card]->width - ray->text_x - 1;
	ray->text_step = 1.0 * root->walls_texture[ray->card]->height / ray->wall_height;
	ray->text_pos = (ray->wall_start - root->height / 2 + ray->wall_height / 2) * ray->text_step;
	return (ray);
}

t_ray	*ray_core(t_root *root, int i)
{
	t_ray			*ray;

	ray = ray_init(root, i);
	if (ray == 0)
		return (0);
	if (ray->card % 2)
		ray->wall_dist = (ray->pos_x - root->pos_x + (1 - ray->ext_x) / 2) / ray->dir_x;
	else
		ray->wall_dist = (ray->pos_y - root->pos_y + (1 - ray->ext_y) / 2) / ray->dir_y;
	ray->wall_height = (int)(root->height / ray->wall_dist);
	ray->wall_start = -ray->wall_height / 2 + root->height / 2;
	if (ray->wall_start < 0)
		ray->wall_start = 0;
	ray->wall_end = ray->wall_height / 2 + root->height / 2;
	if (ray->wall_end >= root->height)
		ray->wall_end = root->height - 1;
	return (ray_texture(root, ray));
}

void	draw(t_root *root, t_ray *ray, int i)
{
	int				color[4];
	int				j;

	color[0] = 0x0000FF00;
	color[1] = 0x00FF0000;
	color[2] = 0x00FFFF00;
	color[3] = 0x000000FF;
	j = 0;
	while (j < ray->wall_start)
	{
		mlx_draw_pixel(root->mlx_img, i, j, root->ceil_color);
		mlx_draw_pixel(root->mlx_img, i, root->height - j - 1, root->floor_color);
		j++;
	}
	while (j < ray->wall_end)
	{
		ray->text_y = (int)ray->text_pos & (root->walls_texture[ray->card]->height - 1);
		ray->text_pos += ray->text_step;
		mlx_draw_pixel(root->mlx_img, i, j, color[ray->card]);
		j++;
	}
}

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
		draw(root, ray, i);
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
