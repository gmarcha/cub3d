/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_left.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamarcha <gamarcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 19:38:23 by user42            #+#    #+#             */
/*   Updated: 2021/08/20 17:09:28 by gamarcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotate_left(t_root *root)
{
	double			tmp;
	double			ratio;

	ratio = ROT_SPEED * root->velocity_left;
	tmp = root->dir_x;
	root->dir_x = tmp * cos(ratio) - root->dir_y * sin(ratio);
	root->dir_y = tmp * sin(ratio) + root->dir_y * cos(ratio);
	tmp = root->plane_x;
	root->plane_x = tmp * cos(ratio) - root->plane_y * sin(ratio);
	root->plane_y = tmp * sin(ratio) + root->plane_y * cos(ratio);
	if (root->velocity_left < VELOCITY)
		root->velocity_left++;
}
