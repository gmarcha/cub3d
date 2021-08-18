/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 19:38:38 by user42            #+#    #+#             */
/*   Updated: 2021/08/18 19:38:38 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_root	*check_info(t_root *root)
{
	int				i;

	i = 0;
	while (i < 4)
		if (root->walls_texture[i++] == 0)
			return (destroy(root, 2, "Error\nTexture is missing"));
	if (root->floor_color == -1 || root->ceil_color == -1)
		return (destroy(root, 2, "Error\nFloor or ceil color is missing"));
	return (root);
}
