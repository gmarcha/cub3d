/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 19:40:39 by user42            #+#    #+#             */
/*   Updated: 2021/08/18 19:40:39 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_ray	*ray_texture(t_root *root, t_ray *ray)
{
	t_img			*img;

	img = root->walls_texture[ray->card];
	if (ray->card % 2 == 0)
		ray->wall_coord = root->pos_x + ray->dir_x * ray->wall_dist;
	else
		ray->wall_coord = root->pos_y + ray->dir_y * ray->wall_dist;
	ray->wall_coord -= floor(ray->wall_coord);
	ray->text_x = (int)(ray->wall_coord * (double)img->width);
	if ((ray->card % 2 && ray->dir_x > 0)
		|| (ray->card % 2 == 0 && ray->dir_y < 0))
		ray->text_x = (double)img->width - ray->text_x - 1;
	ray->text_step = 1.0 * img->height / ray->wall_height;
	ray->text_pos
		= (ray->wall_start - root->height / 2 + ray->wall_height / 2)
		* ray->text_step;
	return (ray);
}
