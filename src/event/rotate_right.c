/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_right.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 19:38:26 by user42            #+#    #+#             */
/*   Updated: 2021/08/18 19:38:26 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotate_right(t_root *root)
{
	double			tmp;

	tmp = root->dir_x;
	root->dir_x = tmp * cos(-ROTATION_SPEED) - root->dir_y * sin(-ROTATION_SPEED);
	root->dir_y = tmp * sin(-ROTATION_SPEED) + root->dir_y * cos(-ROTATION_SPEED);
	tmp = root->plane_x;
	root->plane_x = tmp * cos(-ROTATION_SPEED) - root->plane_y * sin(-ROTATION_SPEED);
	root->plane_y = tmp * sin(-ROTATION_SPEED) + root->plane_y * cos(-ROTATION_SPEED);
}
