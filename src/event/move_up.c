/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_up.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamarcha <gamarcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 19:38:15 by user42            #+#    #+#             */
/*   Updated: 2021/08/19 03:15:36 by gamarcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_up(t_root *root)
{
	if (root->map[(int)(root->pos_x + root->dir_x)][(int)root->pos_y] != 1)
		root->pos_x += root->dir_x;
	if (root->map[(int)root->pos_x][(int)(root->pos_y + root->dir_y)] != 1)
		root->pos_y += root->dir_y;
}
