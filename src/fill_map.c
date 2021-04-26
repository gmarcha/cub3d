#include "cub3d.h"

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
