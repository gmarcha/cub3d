/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_value.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 19:40:10 by user42            #+#    #+#             */
/*   Updated: 2021/08/18 19:40:10 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_root	*parse_value(t_root *root, char **buf)
{
	if (**buf == 'F')
	{
		(*buf)++;
		if (parse_color(root, buf, &root->floor_color) == 0)
			return (0);
	}
	if (**buf == 'C')
	{
		(*buf)++;
		if (parse_color(root, buf, &root->ceil_color) == 0)
			return (0);
	}
	return (root);
}
