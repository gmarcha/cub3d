#include "cub3d.h"

int	button_destroy(int keycode, t_root *root)
{
	(void)keycode;
	destroy(root, 0, 0);
	exit(0);
}
