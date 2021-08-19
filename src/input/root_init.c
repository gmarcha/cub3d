/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   root_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 19:40:18 by user42            #+#    #+#             */
/*   Updated: 2021/08/18 19:40:18 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	player_mov_init(t_root *root)
{
	root->move_up = 0;
	root->move_down = 0;
	root->move_left = 0;
	root->move_right = 0;
	root->speed_up = 1;
	root->speed_down = 1;
	root->speed_left = 1;
	root->speed_right = 1;
	root->rotate_left = 0;
	root->rotate_right = 0;
	root->velocity_left = 1;
	root->velocity_right = 1;
}

t_root	*root_init(void)
{
	t_root			*root;
	int				i;

	root = (t_root *)malloc(sizeof(t_root));
	if (root == 0)
		return (destroy(root, 0, "Error\nCan't allocate memory"));
	root->width = SCREEN_WIDTH;
	root->height = SCREEN_HEIGHT;
	i = 0;
	while (i < 4)
		root->walls_texture[i++] = 0;
	root->floor_color = -1;
	root->ceil_color = -1;
	root->map = 0;
	player_mov_init(root);
	root->mlx = mlx_init();
	if (root->mlx == 0)
		return (destroy(root, 2, "Error\nCan't init mlx"));
	return (root);
}
