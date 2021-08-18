/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 19:39:57 by user42            #+#    #+#             */
/*   Updated: 2021/08/18 19:39:57 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_root	*parse_map(t_root *root, char *buf)
{
	int				i;
	int				j;
	int				k;

	k = 0;
	j = 0;
	i = 0;
	root->dir_x = 0;
	root->dir_y = 0;
	root->plane_x = 0;
	root->plane_y = 0;
	while (j < root->size_line + 2)
		root->map[i][j++] = -1;
	while (++i < root->nb_lines + 1)
	{
		j = 0;
		root->map[i][j] = -1;
		while (++j < root->size_line + 2)
			k += fill_map(root, i, j, buf[k]);
		k++;
	}
	j = 0;
	while (j < root->size_line + 2)
		root->map[i][j++] = -1;
	return (valid_map(root, root->map));
}
