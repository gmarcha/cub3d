/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 19:37:20 by user42            #+#    #+#             */
/*   Updated: 2021/08/18 19:37:20 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include <math.h>

# include "mlx.h"
# include "mlx_int.h"
# include "libft.h"

# define SCREEN_WIDTH	640
# define SCREEN_HEIGHT	360

# define MOV_SPEED		0.001
# define ROT_SPEED		0.002
# define SPEED			60
# define VELOCITY		10

# define NORTH			0
# define SOUTH			2
# define EAST			1
# define WEST			3

typedef struct s_root
{
	void			*mlx;
	void			*mlx_win;
	t_img			*mlx_img;
	int				width;
	int				height;
	t_img			*walls_texture[4];
	int				floor_color;
	int				ceil_color;
	int				**map;
	int				nb_lines;
	int				size_line;
	int				player_orientation;
	double			pos_x;
	double			pos_y;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
	int				move_up;
	int				move_down;
	int				move_left;
	int				move_right;
	int				speed_up;
	int				speed_down;
	int				speed_left;
	int				speed_right;
	int				rotate_left;
	int				rotate_right;
	int				velocity_left;
	int				velocity_right;
}					t_root;

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
}					t_ray;

///  ////////////////////////////////////////////////////  ///
///  ///          INPUT PARSING AND CHECKING          ///  ///
///  ////////////////////////////////////////////////////  ///

t_root				*init(char *file);
t_root				*init_scene(char *file);
t_root				*parse_scene(char *buf);

t_root				*root_init(void);
t_root				*parse_info(t_root *root, char **buf);
t_root				*parse_wall(t_root *root, char **buf);
t_root				*parse_texture(t_root *root, char **buf, t_img **img);
t_root				*parse_value(t_root *root, char **buf);
t_root				*parse_color(t_root *root, char **buf, int *floor);
t_root				*check_info(t_root *root);

int					**init_map(t_root *root, char *buf);
t_root				*size_map(t_root *root, char *buf);
t_root				*check_map(t_root *root, char c, int *max, int *player);
t_root				*parse_map(t_root *root, char *buf);
int					fill_map(t_root *root, int i, int j, char c);
t_root				*valid_map(t_root *root, int **map);

///  //////////////////////////////////////////////  ///
///  ///          RAYCASTING MECHANISM          ///  ///
///  //////////////////////////////////////////////  ///

t_ray				*ray_core(t_root *root, int i);
t_ray				*ray_init(t_root *root, int i);
t_ray				*ray_dist(t_root *root, t_ray *ray);
t_ray				*ray_casting(t_root *root, t_ray *ray);
t_ray				*ray_texture(t_root *root, t_ray *ray);

///  /////////////////////////////////////////  ///
///  ///          ENGINE HANDLING          ///  ///
///  /////////////////////////////////////////  ///

int					loop_routine(t_root *root);
void				update(t_root *root);

///  ////////////////////////////////////////  ///
///  ///          DRAWING FRAMES          ///  ///
///  ////////////////////////////////////////  ///

t_root				*draw_core(t_root *root);
void				draw_env(t_root *r, t_ray *ray, int i);

///  ////////////////////////////////////////  ///
///  ///          EVENT HANDLING          ///  ///
///  ////////////////////////////////////////  ///

int					key_press(int keycode, t_root *root);
int					key_release(int keycode, t_root *root);
void				move_up(t_root *root);
void				move_down(t_root *root);
void				move_left(t_root *root);
void				move_right(t_root *root);
void				rotate_left(t_root *root);
void				rotate_right(t_root *root);

///  ////////////////////////////////////////  ///
///  ///          UTIL FUNCTIONS          ///  ///
///  ////////////////////////////////////////  ///

int					**allocate_map(int nb_lines, int size_line);
void				*destroy(t_root *root, int flag, char *error);
void				*free_matrix(int **matrix, int size);
void				free_root(t_root *root);
void				mlx_draw_pixel(t_img *mlx_img, int x, int y, int color);
unsigned int		mlx_rgb_to_int(int o, int r, int g, int b);

#endif
