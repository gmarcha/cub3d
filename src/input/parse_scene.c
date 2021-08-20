/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 19:40:01 by user42            #+#    #+#             */
/*   Updated: 2021/08/18 19:40:01 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_root	*parse_scene(char *buf)
{
	t_root			*root;
	int				**tmp;

	root = root_init();
	if (root == 0)
		return (0);
	while (*buf && *buf != ' ' && *buf != '1')
	{
		if (*buf == '\n')
			buf++;
		else
			if (parse_info(root, &buf) == 0)
				return (0);
	}
	if (check_info(root) == 0)
		return (0);
	tmp = init_map(root, buf);
	if (tmp == 0)
		return (0);
	root->map = tmp;
	if (parse_map(root, buf) == 0)
		return (0);
	return (root);
}
