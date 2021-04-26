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

# define SCREEN_WIDTH 1920
# define SCREEN_HEIGHT 1080

typedef struct s_root
{
	void			*mlx;
	void			*mlx_win;
	t_img			*mlx_img;
	int				width;
	int				height;
	t_img			*walls_texture[4];
	t_img			*sprite_texture;
	int				floor_color;
	int				ceil_color;
	int				**map;
	int				nb_lines;
	int				size_line;
}				t_root;

t_root				*check_info(t_root *root);

void				*free_matrix(int **matrix, int size);
void				free_root(t_root *root);
void				*destroy(t_root *root, int flag, char *error);

t_root				*init_scene(char *file);

t_root				*init(char *file);

void				mlx_draw_pixel(t_img *mlx_img, int x, int y, int color);
int					mlx_rgb_to_int(int o, int r, int g, int b);

t_root				*parse_color(t_root *root, char **buf, int *floor);

t_root				*parse_info(t_root *root, char **buf);

t_root				*parse_resolution(t_root *root, char **buf);

t_root				*parse_scene(char *buf);

t_root				*parse_texture(t_root *root, char **buf, t_img **img);

t_root				*parse_value(t_root *root, char **buf);

t_root				*parse_wall(t_root *root, char **buf);

t_root				*root_init(void);

int					ft_strclen(char *s, int c);
int					is_space(int c);
int					**allocate_map(int nb_lines, int size_line);
void				print_map(int **map, int nb_lines, int size_line);
void				draw_square(t_img *img, int color);

#endif