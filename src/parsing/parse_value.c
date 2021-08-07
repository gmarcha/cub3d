#include "cub3d.h"

t_root	*parse_value(t_root *root, char **buf)
{
	if (**buf == 'R')
	{
		(*buf)++;
		if (parse_resolution(root, buf) == 0)
			return (0);
	}
	if (**buf == 'S')
	{
		(*buf)++;
		if (parse_texture(root, buf, &root->sprite_texture) == 0)
			return (0);
	}
	if (**buf == 'F')
	{
		(*buf)++;
		if (parse_color(root, buf, &root->floor_color) == 0)
			return (0);
	}
	if (**buf == 'C')
	{
		(*buf)++;
		if (parse_color(root, buf, &root->ceil_color) == 0)
			return (0);
	}
	return (root);
}