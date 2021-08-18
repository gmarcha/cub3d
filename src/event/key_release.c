/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_release.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 19:37:55 by user42            #+#    #+#             */
/*   Updated: 2021/08/18 19:38:06 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_release(int keycode, t_root *root)
{
	if (keycode == 119)
		root->move_up = 0;
	else if (keycode == 115)
		root->move_down = 0;
	else if (keycode == 97)
		root->move_left = 0;
	else if (keycode == 100)
		root->move_right = 0;
	else if (keycode == 65361)
		root->rotate_left = 0;
	else if (keycode == 65363)
		root->rotate_right = 0;
	return (1);
}
