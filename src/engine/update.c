/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamarcha <gamarcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 19:38:28 by user42            #+#    #+#             */
/*   Updated: 2021/08/19 19:11:16 by gamarcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	update(t_root *root)
{
	if (root->move_up != 0)
		move_up(root);
	if (root->move_down != 0)
		move_down(root);
	if (root->move_left != 0)
		move_left(root);
	if (root->move_right != 0)
		move_right(root);
	if (root->rotate_left != 0)
		rotate_left(root);
	if (root->rotate_right != 0)
		rotate_right(root);
}
