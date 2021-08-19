/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_root.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamarcha <gamarcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 19:40:51 by user42            #+#    #+#             */
/*   Updated: 2021/08/19 03:39:25 by gamarcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_root(t_root *root)
{
	int				i;

	if (root->map)
		free_matrix(root->map, root->nb_lines + 2);
	i = -1;
	while (++i < 4)
		if (root->walls_texture[i])
			mlx_destroy_image(root->mlx, root->walls_texture[i]);
	if (root->mlx)
	{
		mlx_destroy_display(root->mlx);
		free(root->mlx);
	}
	free(root);
}
