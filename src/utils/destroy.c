#include "cub3d.h"

void	*destroy(t_root *root, int flag, char *error)
{
	if (flag > 3)
		mlx_destroy_image(root->mlx, root->mlx_img);
	if (flag > 2)
		mlx_destroy_window(root->mlx, root->mlx_win);
	if (flag > 0)
		free_root(root);
	if (error)
		ft_putendl_fd(error, 2);
	return (0);
}
