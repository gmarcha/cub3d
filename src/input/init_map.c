/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 19:38:48 by user42            #+#    #+#             */
/*   Updated: 2021/08/18 19:38:48 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	**init_map(t_root *root, char *buf)
{
	int				**map;

	root->nb_lines = 1;
	root->size_line = 0;
	if (size_map(root, buf) == 0)
		return (0);
	if (root->nb_lines < 3 || root->size_line < 3)
		return (destroy(root, 2, "Error\nMap is too little"));
	map = allocate_map(root->nb_lines + 2, root->size_line + 2);
	if (map == 0)
		return (destroy(root, 2, "Error\nCan't allocate memory"));
	return (map);
}
