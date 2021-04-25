#include "cub3d.h"

t_root	*parse_info(t_root *root, char **buf)
{
	if ((**buf == 'N' && (*buf)[1] == 'O') || (**buf == 'S' && (*buf)[1] == 'O')
	|| (**buf == 'W' && (*buf)[1] == 'E') || (**buf == 'E' && (*buf)[1] == 'A'))
	{
		if (parse_wall(root, buf) == 0)
			return (0);
		return (root);
	}
	if (**buf == 'R' || **buf == 'S' || **buf == 'F' || **buf == 'C')
	{
		if (parse_value(root, buf) == 0)
			return (0);
		return (root);
	}
	return (destroy(root, 2, "error: wrong identifier"));
}
