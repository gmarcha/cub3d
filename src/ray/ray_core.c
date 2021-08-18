/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_core.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 19:40:31 by user42            #+#    #+#             */
/*   Updated: 2021/08/18 19:40:31 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_ray	*ray_core(t_root *root, int i)
{
	t_ray			*ray;

	ray = ray_init(root, i);
	if (ray == 0)
		return (0);
	if (ray->card % 2)
		ray->wall_dist
			= (ray->pos_x - root->pos_x + (1 - ray->ext_x) / 2) / ray->dir_x;
	else
		ray->wall_dist
			= (ray->pos_y - root->pos_y + (1 - ray->ext_y) / 2) / ray->dir_y;
	ray->wall_height = (int)(root->height / ray->wall_dist);
	ray->wall_start = -ray->wall_height / 2 + root->height / 2;
	if (ray->wall_start < 0)
		ray->wall_start = 0;
	ray->wall_end = ray->wall_height / 2 + root->height / 2;
	if (ray->wall_end >= root->height)
		ray->wall_end = root->height - 1;
	return (ray_texture(root, ray));
}
