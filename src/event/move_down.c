#include "cub3d.h"

void	move_down(t_root *root)
{
	if (root->map[(int)(root->pos_x - root->dir_x) * MOVE_SPEED][(int)root->pos_y] != 1)
		root->pos_x -= root->dir_x * MOVE_SPEED;
	if (root->map[(int)root->pos_x][(int)(root->pos_y - root->dir_y) * MOVE_SPEED] != 1)
		root->pos_y -= root->dir_y * MOVE_SPEED;
}
