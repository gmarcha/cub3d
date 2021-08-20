/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_up.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamarcha <gamarcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 19:38:15 by user42            #+#    #+#             */
/*   Updated: 2021/08/20 17:50:08 by gamarcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_up(t_root *root)
{
	double			ratio;

	ratio = MOV_SPEED * root->speed_up;
	if (root->map[(int)((root->pos_x + root->dir_x))][(int)root->pos_y] != 1)
		root->pos_x += root->dir_x * ratio;
	if (root->map[(int)root->pos_x][(int)((root->pos_y + root->dir_y))] != 1)
		root->pos_y += root->dir_y * ratio;
	if (root->speed_up < SPEED)
		root->speed_up++;
}
