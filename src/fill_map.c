#include "cub3d.h"

int	fill_map(t_root *root, int i, int j, char c)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
	{
		root->pos_x = j;
		root->pos_y = i;
		if (c == 'E')
			root->dir_x = 1;
		if (c == 'W')
			root->dir_x = -1;
		if (c == 'S')
			root->dir_y = 1;
		if (c == 'N')
			root->dir_y = -1;
	}
	if (c == '0')
		root->map[i][j] = 0;
	if (c == '1')
		root->map[i][j] = 1;
	if (c == '2')
		root->map[i][j] = 2;
	if (c == 0 || c == '\n' || c == ' ')
		root->map[i][j] = -1;
	if (c && c != '\n')
		return (1);
	return (0);
}
