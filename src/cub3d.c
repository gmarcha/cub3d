#include "cub3d.h"

int					ft_strclen(char *s, int c)
{
	int			i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

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

int					mlx_rgb_to_int(int o, int r, int g, int b)
{
	return(o << 24 | r << 16 | g << 8 | b);
}

void				draw_square(t_img *img, int color)
{
	for (int i = 0; i < 640; i++)
		for (int j = 0; j < 480; j++)
			mlx_draw_pixel(img, i, j, color);
}

void				free_root(t_root *root)
{
	int				i;

	i = 0;
	while (i < 4)
		if (root->walls_texture[i++])
			free(root->walls_texture[i]);
	if (root->sprite_texture)
		free(root->sprite_texture);
	if (root->map)
	{
		i = 0;
		while (i < root->nb_lines)
			free(root->map[i++]);
		free(root->map);
	}
	free(root);
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
		free_root(root);
	if (error)
		ft_putendl_fd(error, 2);
	return (0);
}

t_root				*parse_resolution(t_root *root, char **buf)
{
	if (root->window_width != -1 || root->window_height != -1)
		return (destroy(root, 2, "error: resolution: multiple definition"));
	while (**buf && is_space(**buf))
		(*buf)++;
	root->window_width = 0;
	while (**buf >= '0' && **buf <= '9')
		root->window_width = root->window_width * 10 + *(*buf)++ - 48;
	while (**buf && is_space(**buf))
		(*buf)++;
	root->window_height = 0;
	while (**buf >= '0' && **buf <= '9')
		root->window_height = root->window_height * 10 + *(*buf)++ - 48;
	if (**buf != '\n' || root->window_width == 0 || root->window_height == 0)
		return (destroy(root, 2, "error: invalid resolution"));
	if (root->window_width > SCREEN_WIDTH)
		root->window_width = SCREEN_WIDTH;
	if (root->window_height > SCREEN_HEIGHT)
		root->window_height = SCREEN_HEIGHT;
	return (root);
}

t_root				*parse_texture(t_root *root, char **buf, t_img *img)
{
	char			*path;
	int				len;

	if (img)
		return (destroy(root, 2, "error: multiple texture definition"));
	while (**buf && is_space(**buf))
		(*buf)++;
	len = ft_strclen(*buf, '\n');
	path = ft_substr(*buf, 0, len);
	if (path == 0)
		return (destroy(root, 2, "error: no texture file"));
	img = mlx_xpm_file_to_image(root->mlx, path, &img->width, &img->height);
	free(path);
	if (img == 0)
		return (destroy(root, 2, "error: can't load texture"));
	if (**buf != '\n')
		return (destroy(root, 2, "error: invalid texture path"));
	return (root);
}

t_root				*parse_color(t_root *root, char **buf, int floor)
{
	int				rgb[3];
	int				i;

	if (floor != -1)
		return (destroy(root, 2, "error: multiple definition floor or ceil"));
	while (**buf && is_space(**buf))
		(*buf)++;
	i = -1;
	while (++i < 3)
	{
		if (!(**buf >= '0' && **buf <= '9'))
			return (destroy(root, 2, "error: invalid value in color"));
		rgb[i] = 0;
		while (**buf >= '0' && **buf <= '9')
			rgb[i] = rgb[i] * 10 + *(*buf)++ - 48;
		if (rgb[i] > 255)
			return (destroy(root, 2, "error: value is too high in color"));
		if (i < 2 && *(*buf)++ != ',')
			return (destroy(root, 2, "error: invalid separator in color"));
	}
	if (**buf != '\n')
		return (destroy(root, 2, "error: invalid floor or ceil color"));
	floor = mlx_rgb_to_int(0, rgb[0], rgb[1], rgb[2]);
	return (root);
}

t_root				*root_init(void)
{
	t_root			*root;
	int				i;

	root = (t_root *)malloc(sizeof(t_root));
	if (root == 0)
		return (destroy(root, 0, "error: can't allocate memory"));
	root->window_width = -1;
	root->window_height = -1;
	i = 0;
	while (i < 4)
		root->walls_texture[i++] = 0;
	root->sprite_texture = 0;
	root->floor_color = -1;
	root->ceil_color = -1;
	root->map = 0;
	root->mlx = mlx_init();
	if (root->mlx == 0)
		return (destroy(root, 1, "error: can't init mlx"));
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
		{
			if (*buf == 'R')
			{
				buf++;
				if (parse_resolution(root, &buf) == 0)
					return (0);
			}
			else if (*buf == 'N' && buf[1] == 'O')
			{
				buf += 2;
				if (parse_texture(root, &buf, root->walls_texture[0]) == 0)
					return (0);
			}
			else if (*buf == 'S' && buf[1] == 'O')
			{
				buf += 2;
				if (parse_texture(root, &buf, root->walls_texture[2]) == 0)
					return (0);
			}
			else if (*buf == 'W' && buf[1] == 'E')
			{
				buf += 2;
				if (parse_texture(root, &buf, root->walls_texture[1]) == 0)
					return (0);
			}
			else if (*buf == 'E' && buf[1] == 'A')
			{
				buf += 2;
				if (parse_texture(root, &buf, root->walls_texture[3]) == 0)
					return (0);
			}
			else if (*buf == 'S')
			{
				buf++;
				if (parse_texture(root, &buf, root->sprite_texture) == 0)
					return (0);
			}
			else if (*buf == 'F')
			{
				buf++;
				if (parse_color(root, &buf, root->floor_color) == 0)
					return (0);
			}
			else if (*buf == 'C')
			{
				buf++;
				if (parse_color(root, &buf, root->ceil_color) == 0)
					return (0);
			}
			else
				return (destroy(root, 2, "error: wrong identifier"));
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
		return (destroy(0, 0, "error: can't open the scene (*.map)"));
	ret = read(fd, buf, 32768);
	close(fd);
	if (ret == -1)
		return (destroy(0, 0, "error: can't read the scene (*.map)"));
	if (ret == 0)
		return (destroy(0, 0, "error: scene file is empty"));
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
	root->mlx_win = mlx_new_window(root->mlx, root->window_width, root->window_height, "cub3d");
	if (root->mlx_win == 0)
		return (destroy(root, 2, "error: can't create a new window"));
	root->mlx_img = mlx_new_image(root->mlx, root->window_width, root->window_height);
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
