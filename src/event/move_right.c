/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_right.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamarcha <gamarcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 19:38:12 by user42            #+#    #+#             */
/*   Updated: 2021/08/20 17:08:56 by gamarcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_right(t_root *r)
{
	double			ratio;

	ratio = MOV_SPEED * r->speed_right;
	if (r->player_orientation == SOUTH || r->player_orientation == EAST)
	{
		if (r->map[(int)(r->pos_x - r->plane_x)][(int)r->pos_y] != 1)
			r->pos_x -= r->plane_x * ratio;
		if (r->map[(int)r->pos_x][(int)(r->pos_y - r->plane_y)] != 1)
			r->pos_y -= r->plane_y * ratio;
	}
	else
	{
		if (r->map[(int)(r->pos_x + r->plane_x)][(int)r->pos_y] != 1)
			r->pos_x += r->plane_x * ratio;
		if (r->map[(int)r->pos_x][(int)(r->pos_y + r->plane_y)] != 1)
			r->pos_y += r->plane_y * ratio;
	}
	if (r->speed_right < SPEED)
		r->speed_right++;
}
