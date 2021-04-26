#include "cub3d.h"

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
