#include "cub3d.h"

int					main(int argc, char *argv[])
{
	void			*mlx;

	(void)argc;
	(void)argv;
	mlx = mlx_init();
	if (mlx == 0)
	{
		ft_putendl_fd("error: can't init mlx", 2);
		return (1);
	}
	ft_putendl_fd("Hello World!", 1);
	return (0);
}