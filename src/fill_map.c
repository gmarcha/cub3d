#include "cub3d.h"

void	set_player(t_root *root, int i, int j, char c)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
	{
		root->pos_x = i + 0.5;
		root->pos_y = j + 0.5;
		if (c == 'S')
			root->dir_x = 1;
		if (c == 'N')
			root->dir_x = -1;
		if (c == 'E')
			root->dir_y = -1;
		if (c == 'W')
			root->dir_y = 1;
		root->map[i][j] = 0;
	}
}

int	fill_map(t_root *root, int i, int j, char c)
{
	// static int		count;

	set_player(root, i, j, c);
	if (c == '2')
	{
		root->map[i][j] = 2;
		// root->sprites[count]->pos_x = j;
		// root->sprites[count]->pos_y = i;
		// count++;
	}
	if (c == '1')
		root->map[i][j] = 1;
	if (c == '0')
		root->map[i][j] = 0;
	if (c == 0 || c == '\n' || c == ' ')
		root->map[i][j] = -1;
	if (c && c != '\n')
		return (1);
	return (0);
}
