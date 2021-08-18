/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_dist.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 19:40:34 by user42            #+#    #+#             */
/*   Updated: 2021/08/18 19:40:34 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_ray	*ray_dist(t_root *root, t_ray *ray)
{
	ray->dist_from_x = 1 / ray->dir_x;
	if (ray->dist_from_x < 0)
		ray->dist_from_x *= -1;
	ray->dist_from_y = 1 / ray->dir_y;
	if (ray->dist_from_y < 0)
		ray->dist_from_y *= -1;
	if (ray->dir_x < 0)
		ray->dist_to_x = (root->pos_x - ray->pos_x) * ray->dist_from_x;
	else
		ray->dist_to_x = (ray->pos_x + 1 - root->pos_x) * ray->dist_from_x;
	if (ray->dir_y < 0)
		ray->dist_to_y = (root->pos_y - ray->pos_y) * ray->dist_from_y;
	else
		ray->dist_to_y = (ray->pos_y + 1 - root->pos_y) * ray->dist_from_y;
	return (ray_casting(root, ray));
}
