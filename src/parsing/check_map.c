#include "cub3d.h"

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
