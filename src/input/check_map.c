/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 19:38:43 by user42            #+#    #+#             */
/*   Updated: 2021/08/18 19:38:43 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_root	*check_map(t_root *root, char c, int *max, int *player)
{
	if (c != 32 && (c < '0' || c > '1'))
	{
		if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		{
			if (*player)
				return (destroy(root, 2, "Error\nToo much player in map"));
			(*player)++;
		}
		else
			return (destroy(root, 2, "Error\nInvalid character in map"));
	}
	(*max)++;
	return (root);
}
