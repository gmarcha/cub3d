#include "cub3d.h"

static int	iscub(char *file)
{
	int				len;

	len = ft_strlen(file);
	if (file == 0)
		return (0);
	if (len < 5)
		return (0);
	if (ft_strcmp(file + len - 4, ".cub") != 0)
		return (0);
	return (1);
}

static int	invalid_args(int ac, char *av[])
{
	if (ac != 2)
	{
		ft_putendl_fd("error: invalid number of arguments", 2);
		return (-1);
	}
	if (iscub(av[1]) == 0)
	{
		ft_putendl_fd("error: invalid extension to .cub file", 2);
		return (-1);
	}
	return (0);
}

int	main(int ac, char *av[])
{
	t_root			*root;

	if (invalid_args(ac, av) == -1)
		return (EXIT_FAILURE);
	root = init(av[1]);
	if (root == 0)
		return (EXIT_FAILURE);
	if (draw_core(root) == 0)
		return (EXIT_FAILURE);
	mlx_do_sync(root->mlx);
	mlx_hook(root->mlx_win, 2, 1L << 0, key_press, root);
	mlx_hook(root->mlx_win, 3, 1L << 1, key_release, root);
	mlx_hook(root->mlx_win, 17, 1L << 17, button_destroy, root);
	mlx_loop(root->mlx);
	return (EXIT_SUCCESS);
}
