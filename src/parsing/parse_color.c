#include "cub3d.h"

t_root	*parse_color(t_root *root, char **buf, int *floor)
{
	int				rgb[3];
	int				i;

	if (*floor != -1)
		return (destroy(root, 2, "error: multiple definition floor or ceil"));
	while (**buf && ft_isspace(**buf))
		(*buf)++;
	i = -1;
	while (++i < 3)
	{
		if (!(**buf >= '0' && **buf <= '9'))
			return (destroy(root, 2, "error: invalid value in color"));
		rgb[i] = 0;
		while (**buf >= '0' && **buf <= '9')
			rgb[i] = rgb[i] * 10 + *(*buf)++ - 48;
		if (rgb[i] > 255)
			return (destroy(root, 2, "error: value is too high in color"));
		if (i < 2 && *(*buf)++ != ',')
			return (destroy(root, 2, "error: invalid separator in color"));
	}
	if (**buf != '\n')
		return (destroy(root, 2, "error: invalid floor or ceil color"));
	*floor = mlx_rgb_to_int(0, rgb[0], rgb[1], rgb[2]);
	return (root);
}
