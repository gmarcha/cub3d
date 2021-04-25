#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include <stdio.h>
# include <math.h>

# include <mlx.h>
# include <mlx_int.h>
# include "libft.h"

typedef struct s_root
{
	void			*mlx;
	void			*mlx_win;
	t_img			*mlx_img;
	int				window_width;
	int				window_height;
	t_img			*walls_texture[4];
	t_img			*sprite_texture;
	int				floor_color;
	int				ceil_color;
	int				**map;
	int				nb_lines;
}				t_root;

#endif