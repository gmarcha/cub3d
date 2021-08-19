/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamarcha <gamarcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 19:37:48 by user42            #+#    #+#             */
/*   Updated: 2021/08/19 22:02:47 by gamarcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_press(int keycode, t_root *root)
{
	if (keycode == 65307)
		mlx_loop_end(root->mlx);
	else if (keycode == 119)
		root->move_up = 1;
	else if (keycode == 115)
		root->move_down = 1;
	else if (keycode == 97)
		root->move_left = 1;
	else if (keycode == 100)
		root->move_right = 1;
	else if (keycode == 65361)
		root->rotate_left = 1;
	else if (keycode == 65363)
		root->rotate_right = 1;
	return (1);
}
