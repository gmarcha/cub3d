#include "cub3d.h"

int					main(void)
{
	void			*mlx;
	void			*mlx_win;
	//t_data			img;

	mlx = mlx_init();
	if (mlx == 0)
	{
		ft_putendl_fd("error: can't init mlx", 2);
		return (1);
	}
	mlx_win = mlx_new_window(mlx, 1920, 1080, "cub3d");
	if (mlx_win == 0)
	{
		ft_putendl_fd("error: can't create a new window", 2);
		return (1);
	}
	ft_putendl_fd("Hello World!", 1);
	mlx_loop(mlx);
	return (0);
}