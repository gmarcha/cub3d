#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include <stdio.h>
# include <math.h>

# include "libft.h"
# include <mlx.h>
# include <mlx_int.h>

# define WINDOW_WIDTH 640
# define WINDOW_HEIGHT 480

typedef struct s_root
{
	void			*mlx;
	void			*mlx_win;
	t_img			*mlx_img;
}				t_root;

#endif