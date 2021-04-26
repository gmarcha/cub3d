#include "cub3d.h"

t_root	*valid_map(t_root *root, int **map)
{
	int				i;
	int				j;

	i = 0;
	while (++i < root->nb_lines + 1)
	{
		j = 0;
		while (++j < root->size_line + 1)
		{
			if (map[i][j] == 0)
				if (map[i - 1][j] == -1 || map[i + 1][j] == -1
				|| map[i][j - 1] == -1 || map[i][j + 1] == -1)
					return (destroy(root, 2, "error: invalid map"));
			if (map[i][j] == -1)
				if (map[i - 1][j] == 0 || map[i + 1][j] == 0
				|| map[i][j - 1] == 0 || map[i][j + 1] == 0
				|| map[i - 1][j] == 2 || map[i + 1][j] == 2
				|| map[i][j - 1] == 2 || map[i][j + 1] == 2)
					return (destroy(root, 2, "error: invalid map"));
		}
	}
	return (root);
}

int	fill_map(char c, int *n)
{
	if (c == '0' || c == 'N' || c == 'S' || c == 'W' || c == 'E')
		*n = 0;
	if (c == '1')
		*n = 1;
	if (c == '2')
		*n = 2;
	if (c == 0 || c == '\n' || c == ' ')
		*n = -1;
	if (c && c != '\n')
		return (1);
	return (0);
}

t_root	*parse_map(t_root *root, char *buf)
{
	int				i;
	int				j;
	int				k;

	k = 0;
	j = 0;
	i = 0;
	while (j < root->size_line + 2)
		root->map[i][j++] = -1;
	while (++i < root->nb_lines + 1)
	{
		j = 0;
		root->map[i][j] = -1;
		while (++j < root->size_line + 2)
			k += fill_map(buf[k], &root->map[i][j]);
		k++;
	}
	j = 0;
	while (j < root->size_line + 2)
		root->map[i][j++] = -1;
	return (valid_map(root, root->map));
}

t_root	*check_map(t_root *root, char c, int *max, int *player)
{
	if (c != 32 && (c < '0' || c > '2'))
	{
		if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		{
			if (*player)
				return (destroy(root, 2, "error: too much player in map"));
			(*player)++;
		}
		else
			return (destroy(root, 2, "error: invalid character in map"));
	}
	(*max)++;
	return (root);
}

t_root	*size_map(t_root *root, char *buf)
{
	int				player;
	int				max;
	int				i;

	player = 0;
	max = 0;
	i = -1;
	while (buf[++i])
	{
		if (buf[i] == '\n')
		{
			if (root->size_line < max)
				root->size_line = max;
			max = 0;
			root->nb_lines++;
		}
		else
			if (check_map(root, buf[i], &max, &player) == 0)
				return (0);
	}
	if (root->size_line < max)
		root->size_line = max;
	return (root);
}

int	**init_map(t_root* root, char *buf)
{
	int				**map;

	root->nb_lines = 1;
	root->size_line = 0;
	if (size_map(root, buf) == 0)
		return (0);
	if (root->nb_lines < 3 || root->size_line < 3)
		return (destroy(root, 2, "error: map is too little"));
	map = allocate_map(root->nb_lines + 2, root->size_line + 2);
	if (map == 0)
		return (destroy(root, 2, "error: can't allocate memory"));
	return (map);
}

t_root	*parse_scene(char *buf)
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
	root->map = init_map(root, buf);
	if (root->map == 0)
		return (0);
	if (parse_map(root, buf) == 0)
	 	return (0);
	return (root);
}
