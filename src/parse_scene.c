#include "cub3d.h"

void	*free_matrix(int **matrix, int size)
{
	int				i;

	i = 0;
	while (i < size)
		free(matrix[i++]);
	free(matrix);
	return (0);
}

int	**allocate_map(int nb_lines, int size_line)
{
	int				**map;
	int				i;

	map = (int **)malloc(sizeof(int *) * nb_lines);
	if (map == 0)
		return (0);
	i = 0;
	while (i < nb_lines)
	{
		map[i] = (int *)malloc(sizeof(int) * size_line);
		if (map[i] == 0)
			return (free_matrix(map, i));
		i++;
	}
	return (map);
}

void	fill_map(t_root *root, char *buf, int **map)
{
	int				i;
	int				j;
	int				k;

	k = 0;
	j = 0;
	i = 0;
	while (j < root->size_line + 2)
		map[i][j++] = -1;
	while (++i < root->nb_lines + 1)
	{
		j = 0;
		map[i][j] = -1;
		while (++j < root->size_line + 2)
		{
			if (buf[k] == '0' || buf[k] == 'N')
				map[i][j] = 0;
			if (buf[k] == '1')
				map[i][j] = 1;
			if (buf[k] == '2')
				map[i][j] = 2;
			if (buf[k] == ' ')
				map[i][j] = -1;
			if (buf[k] == 0 || buf[k] == '\n')
				map[i][j] = -1;
			if (buf[k] && buf[k] != '\n')
				k++;
		}
		k++;
	}
	j = 0;
	while (j < root->size_line + 2)
		map[i][j++] = -1;

	i = 0;
	while (i < root->nb_lines + 2)
	{
		j = 0;
		while (j < root->size_line + 2)
		{
			if (map[i][j] == 1)
				printf("X");
			else
				printf(" ");
			j++;
		}
		printf("\n");
		i++;
	}
}

int	**parse_map(t_root* root, char *buf)
{
	int				**map;
	int				i;
	int				max;
	int				player;

	player = 0;
	root->nb_lines = 1;
	root->size_line = 0;
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
		{
			if (buf[i] != 32 && (buf[i] < '0' || buf[i] > '2'))
			{
				if (buf[i] == 'N' || buf[i] == 'S'
				|| buf[i] == 'W' || buf[i] == 'E')
				{
					if (player)
						return (destroy(root, 2, "error: too much player in map"));
					player++;
				}
				else
					return (destroy(root, 2, "error: invalid character in map"));
			}
			max++;
		}
	}
	if (root->size_line < max)
		root->size_line = max;
	if (root->nb_lines < 3 || root->size_line < 3)
		return (destroy(root, 2, "error: map is too little"));
	map = allocate_map(root->nb_lines + 2, root->size_line + 2);
	if (map == 0)
		return (destroy(root, 2, "error: can't allocate memory"));
	fill_map(root, buf, map);
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
	root->map = parse_map(root, buf);
	if (root->map == 0)
		return (0);
	// if (check_map(root) == 0)
	// 	return (0);
	return (root);
}
