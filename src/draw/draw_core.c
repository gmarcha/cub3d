/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_core.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 19:37:31 by user42            #+#    #+#             */
/*   Updated: 2021/08/18 19:37:32 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_root	*draw_core(t_root *root)
{
	t_ray			*ray;
	int				i;

	i = 0;
	while (i < root->width)
	{
		ray = ray_core(root, i);
		if (ray == 0)
			return (destroy(root, 4, "Error\nCan't draw"));
		draw_env(root, ray, i);
		free(ray);
		i++;
	}
	mlx_put_image_to_window(root->mlx, root->mlx_win, root->mlx_img, 0, 0);
	return (root);
}
