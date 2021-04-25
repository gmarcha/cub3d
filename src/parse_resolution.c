#include "cub3d.h"

t_root	*parse_resolution(t_root *root, char **buf)
{
	if (root->window_width != -1 || root->window_height != -1)
		return (destroy(root, 2, "error: resolution: multiple definition"));
	while (**buf && is_space(**buf))
		(*buf)++;
	root->window_width = 0;
	while (**buf >= '0' && **buf <= '9')
		root->window_width = root->window_width * 10 + *(*buf)++ - 48;
	while (**buf && is_space(**buf))
		(*buf)++;
	root->window_height = 0;
	while (**buf >= '0' && **buf <= '9')
		root->window_height = root->window_height * 10 + *(*buf)++ - 48;
	if (**buf != '\n' || root->window_width == 0 || root->window_height == 0)
		return (destroy(root, 2, "error: invalid resolution"));
	if (root->window_width > SCREEN_WIDTH)
		root->window_width = SCREEN_WIDTH;
	if (root->window_height > SCREEN_HEIGHT)
		root->window_height = SCREEN_HEIGHT;
	return (root);
}
