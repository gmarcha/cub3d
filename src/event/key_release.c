#include "cub3d.h"

int	key_release(int keycode, t_root *root)
{
	if (keycode == 119)
		root->move_up = 0;
	else if (keycode == 115)
		root->move_down = 0;
	else if (keycode == 97)
		root->move_left = 0;
	else if (keycode == 100)
		root->move_right = 0;
	else if (keycode == 65361)
		root->rotate_left = 0;
	else if (keycode == 65363)
		root->rotate_right = 0;
	return (1);
}