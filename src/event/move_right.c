/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_right.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamarcha <gamarcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 19:38:12 by user42            #+#    #+#             */
/*   Updated: 2021/08/19 03:16:19 by gamarcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_right(t_root *r)
{
	if (r->player_orientation == SOUTH || r->player_orientation == EAST)
	{
		if (r->map[(int)(r->pos_x - r->plane_x)][(int)r->pos_y] != 1)
			r->pos_x -= r->plane_x;
		if (r->map[(int)r->pos_x][(int)(r->pos_y - r->plane_y)] != 1)
			r->pos_y -= r->plane_y;
	}
	else
	{
		if (r->map[(int)(r->pos_x + r->plane_x)][(int)r->pos_y] != 1)
			r->pos_x += r->plane_x;
		if (r->map[(int)r->pos_x][(int)(r->pos_y + r->plane_y)] != 1)
			r->pos_y += r->plane_y;
	}
}
