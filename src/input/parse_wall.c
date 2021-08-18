#include "cub3d.h"

t_root	*parse_wall(t_root *root, char **buf)
{
	if (**buf == 'N' && (*buf)[1] == 'O')
	{
		(*buf) += 2;
		if (parse_texture(root, buf, &root->walls_texture[1]) == 0)
			return (0);
	}
	if (**buf == 'S' && (*buf)[1] == 'O')
	{
		(*buf) += 2;
		if (parse_texture(root, buf, &root->walls_texture[3]) == 0)
			return (0);
	}
	if (**buf == 'W' && (*buf)[1] == 'E')
	{
		(*buf) += 2;
		if (parse_texture(root, buf, &root->walls_texture[0]) == 0)
			return (0);
	}
	if (**buf == 'E' && (*buf)[1] == 'A')
	{
		(*buf) += 2;
		if (parse_texture(root, buf, &root->walls_texture[2]) == 0)
			return (0);
	}
	return (root);
}
