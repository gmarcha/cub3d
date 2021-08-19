/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamarcha <gamarcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 19:37:48 by user42            #+#    #+#             */
/*   Updated: 2021/08/19 03:25:43 by gamarcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	setup_movement(t_root *root, int *move)
{
	*move = 1;
	update(root);
}

int	key_press(int keycode, t_root *root)
{
	if (keycode == 65307)
	{
		destroy(root, 4, 0);
		exit(0);
	}
	if (keycode == 119)
		setup_movement(root, &root->move_up);
	else if (keycode == 115)
		setup_movement(root, &root->move_down);
	else if (keycode == 97)
		setup_movement(root, &root->move_left);
	else if (keycode == 100)
		setup_movement(root, &root->move_right);
	else if (keycode == 65361)
		setup_movement(root, &root->rotate_left);
	else if (keycode == 65363)
		setup_movement(root, &root->rotate_right);
	return (1);
}
