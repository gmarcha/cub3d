#include "cub3d.h"

void	*free_matrix(int **matrix, int size)
{
	int				i;

	i = 0;
	while (i < size)
		free(matrix[i++]);
	free(matrix);
	return (0);
}

void	*free_sprites(t_sprite **sprites, int size)
{
	int				i;

	i = 0;
	while (i < size)
		free(sprites[i++]);
	free(sprites);
	return (0);
}

void	free_root(t_root *root)
{
	int				i;

	if (root->sprites)
		free_sprites(root->sprites, root->nb_sprites);
	if (root->map)
		free_matrix(root->map, root->nb_lines + 2);
	i = -1;
	while (++i < 4)
		if (root->walls_texture[i])
			mlx_destroy_image(root->mlx, root->walls_texture[i]);
	if (root->sprite_texture)
		mlx_destroy_image(root->mlx, root->sprite_texture);
	if (root->mlx)
		mlx_destroy_display(root->mlx);
	free(root);
}

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
