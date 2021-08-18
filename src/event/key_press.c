/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 19:37:48 by user42            #+#    #+#             */
/*   Updated: 2021/08/18 19:37:49 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_press(int keycode, t_root *root)
{
	if (keycode == 65307)
	{
		destroy(root, 4, 0);
		exit(0);
	}
	if (keycode == 119)
	{
		root->move_up = 1;
		update(root);
	}
	else if (keycode == 115)
	{
		root->move_down = 1;
		update(root);
	}
	else if (keycode == 97)
	{
		root->move_left = 1;
		update(root);
	}
	else if (keycode == 100)
	{
		root->move_right = 1;
		update(root);
	}
	else if (keycode == 65361)
	{
		root->rotate_left = 1;
		update(root);
	}
	else if (keycode == 65363)
	{
		root->rotate_right = 1;
		update(root);
	}
	return (1);
}
