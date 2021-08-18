/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 19:38:57 by user42            #+#    #+#             */
/*   Updated: 2021/08/18 19:38:57 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_root	*init(char *file)
{
	t_root			*r;

	r = init_scene(file);
	if (r == 0)
		return (0);
	r->mlx_win = mlx_new_window(r->mlx, r->width, r->height, "cub3d");
	if (r->mlx_win == 0)
		return (destroy(r, 2, "Error\nCan't create a new window"));
	r->mlx_img = mlx_new_image(r->mlx, r->width, r->height);
	if (r->mlx_img == 0)
		return (destroy(r, 3, "Error\nCan't create a new image"));
	return (r);
}
