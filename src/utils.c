#include "cub3d.h"

int	ft_strclen(char *s, int c)
{
	int			i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

int	is_space(int c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

void	draw_square(t_img *img, int color)
{
	int				i;
	int				j;

	i = 0;
	while (i < 640)
	{
		j = 0;
		while (j < 480)
			mlx_draw_pixel(img, i, j++, color);
		i++;
	}
}
