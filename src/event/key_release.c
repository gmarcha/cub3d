/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_release.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamarcha <gamarcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 19:37:55 by user42            #+#    #+#             */
/*   Updated: 2021/08/19 20:11:44 by gamarcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	reset_move(int *move, int *affec)
{
	*move = 0;
	*affec = 1;
}

int	key_release(int keycode, t_root *root)
{
	if (keycode == 119)
		reset_move(&root->move_up, &root->speed_up);
	else if (keycode == 115)
		reset_move(&root->move_down, &root->speed_down);
	else if (keycode == 97)
		reset_move(&root->move_left, &root->speed_left);
	else if (keycode == 100)
		reset_move(&root->move_right, &root->speed_right);
	else if (keycode == 65361)
		reset_move(&root->rotate_left, &root->velocity_left);
	else if (keycode == 65363)
		reset_move(&root->rotate_right, &root->velocity_right);
	return (1);
}
