/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 19:39:14 by user42            #+#    #+#             */
/*   Updated: 2021/08/18 19:39:14 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_root	*parse_info(t_root *root, char **buf)
{
	if ((**buf == 'N' && (*buf)[1] == 'O' && ft_isspace((*buf)[2]) == 1)
		|| (**buf == 'S' && (*buf)[1] == 'O' && ft_isspace((*buf)[2]) == 1)
		|| (**buf == 'W' && (*buf)[1] == 'E' && ft_isspace((*buf)[2]) == 1)
		|| (**buf == 'E' && (*buf)[1] == 'A' && ft_isspace((*buf)[2]) == 1))
	{
		if (parse_wall(root, buf) == 0)
			return (0);
		return (root);
	}
	if ((**buf == 'F' && ft_isspace((*buf)[1]) == 1)
		|| (**buf == 'C' && ft_isspace((*buf)[1]) == 1))
	{
		if (parse_value(root, buf) == 0)
			return (0);
		return (root);
	}
	return (destroy(root, 2, "Error\nWrong identifier"));
}
