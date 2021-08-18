/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 19:38:46 by user42            #+#    #+#             */
/*   Updated: 2021/08/18 19:38:46 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	fill_map(t_root *root, int i, int j, char c)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
	{
		root->pos_x = i + 0.5;
		root->pos_y = j + 0.5;
		if (c == 'S')
		{
			root->player_orientation = SOUTH;
			root->dir_x = 1;
			root->plane_y = 0.8;
		}
		if (c == 'N')
		{
			root->player_orientation = NORTH;
			root->dir_x = -1;
			root->plane_y = 0.8;
		}
		if (c == 'E')
		{
			root->player_orientation = EAST;
			root->dir_y = -1;
			root->plane_x = 0.8;
		}
		if (c == 'W')
		{
			root->player_orientation = WEST;
			root->dir_y = 1;
			root->plane_x = 0.8;
		}
	}
	if (c == '0')
		root->map[i][j] = 0;
	if (c == '1')
		root->map[i][j] = 1;
	if (c == 0 || c == '\n' || c == ' ')
		root->map[i][j] = -1;
	if (c && c != '\n')
		return (1);
	return (0);
}
