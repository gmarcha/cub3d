#include "cub3d.h"

t_root	*parse_resolution(t_root *root, char **buf)
{
	if (root->width != -1 || root->height != -1)
		return (destroy(root, 2, "error: resolution: multiple definition"));
	while (**buf && ft_isspace(**buf))
		(*buf)++;
	root->width = 0;
	while (**buf >= '0' && **buf <= '9')
		root->width = root->width * 10 + *(*buf)++ - 48;
	while (**buf && ft_isspace(**buf))
		(*buf)++;
	root->height = 0;
	while (**buf >= '0' && **buf <= '9')
		root->height = root->height * 10 + *(*buf)++ - 48;
	if (**buf != '\n' || root->width == 0 || root->height == 0)
		return (destroy(root, 2, "error: invalid resolution"));
	if (root->width > SCREEN_WIDTH)
		root->width = SCREEN_WIDTH;
	if (root->height > SCREEN_HEIGHT)
		root->height = SCREEN_HEIGHT;
	return (root);
}
