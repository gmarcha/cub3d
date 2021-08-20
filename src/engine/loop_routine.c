/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_routine.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamarcha <gamarcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 22:07:52 by gamarcha          #+#    #+#             */
/*   Updated: 2021/08/19 22:07:52 by gamarcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	loop_routine(t_root *root)
{
	if (draw_core(root) == NULL)
		return (mlx_loop_end(root->mlx));
	update(root);
	return (1);
}
