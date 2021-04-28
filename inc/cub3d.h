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

# define SCREEN_WIDTH	1920
# define SCREEN_HEIGHT	1080

# define MS				1
# define RS				1

typedef struct s_sprite
{
	int			pos_x;
	int			pos_y;
}				t_sprite;

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
	t_sprite		*sprites;
	int				nb_sprites;
	double			pos_x;
	double			pos_y;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
}				t_root;

typedef struct s_ray
{
	int				pos_x;
	int				pos_y;
	double			dir_x;
	double			dir_y;
	int				ext_x;
	int				ext_y;
	double			dist_from_x;
	double			dist_from_y;
	double			dist_to_x;
	double			dist_to_y;
	int				card;
	double			wall_dist;
	int				wall_height;
	int				wall_start;
	int				wall_end;
	double			wall_coord;
	int				text_x;
	int				text_y;
	double			text_pos;
	double			text_step;
}				t_ray;

t_root				*check_info(t_root *root);

t_root				*check_map(t_root *root, char c, int *max, int *player, int *nb_sprites);

void				*free_matrix(int **matrix, int size);
void				*free_sprites(t_sprite *sprites);
void				free_root(t_root *root);
void				*destroy(t_root *root, int flag, char *error);

void				draw_env(t_root *r, t_ray *ray, int i);

int					fill_map(t_root *root, int i, int j, char c);

int					**init_map(t_root *root, char *buf);

t_root				*init_scene(char *file);

t_root				*init(char *file);

void				mlx_draw_pixel(t_img *mlx_img, int x, int y, int color);
unsigned int		mlx_rgb_to_int(int o, int r, int g, int b);

t_root				*parse_color(t_root *root, char **buf, int *floor);

t_root				*parse_info(t_root *root, char **buf);

t_root				*parse_map(t_root *root, char *buf);

t_root				*parse_resolution(t_root *root, char **buf);

t_root				*parse_scene(char *buf);

t_root				*parse_texture(t_root *root, char **buf, t_img **img);

t_root				*parse_value(t_root *root, char **buf);

t_root				*parse_wall(t_root *root, char **buf);

t_ray				*ray_casting(t_root *root, t_ray *ray);

t_ray				*ray_core(t_root *root, int i);

t_ray				*ray_dist(t_root *root, t_ray *ray);

t_ray				*ray_init(t_root *root, int i);

t_ray				*ray_texture(t_root *root, t_ray *ray);

t_root				*root_init(void);

t_root				*size_map(t_root *root, char *buf);

t_root				*valid_map(t_root *root, int **map);

int					ft_strclen(char *s, int c);
int					is_space(int c);
int					**allocate_map(int nb_lines, int size_line);
t_sprite			*allocate_sprites(int nb_sprites);
void				print_map(int **map, int nb_lines, int size_line);

#endif