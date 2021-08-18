/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 19:40:21 by user42            #+#    #+#             */
/*   Updated: 2021/08/18 19:40:21 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_root	*size_map(t_root *root, char *buf)
{
	int				player;
	int				max;
	int				i;

	player = 0;
	max = 0;
	i = -1;
	while (buf[++i])
	{
		if (buf[i] == '\n')
		{
			if (root->size_line < max)
				root->size_line = max;
			max = 0;
			root->nb_lines++;
		}
		else
			if (check_map(root, buf[i], &max, &player) == 0)
				return (0);
	}
	if (root->size_line < max)
		root->size_line = max;
	return (root);
}
