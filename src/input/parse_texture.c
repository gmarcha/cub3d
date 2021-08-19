/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 19:40:08 by user42            #+#    #+#             */
/*   Updated: 2021/08/18 19:40:08 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_root	*parse_texture(t_root *root, char **buf, t_img **img)
{
	char			*path;
	int				len;
	int				width;
	int				height;

	if (*img)
		return (destroy(root, 2, "Error\nMultiple texture definition"));
	while (**buf && ft_isspace(**buf))
		(*buf)++;
	len = ft_strclen(*buf, " \t\n");
	path = ft_substr(*buf, 0, len);
	if (path == 0)
		return (destroy(root, 2, "Error\nNo texture file"));
	*img = mlx_xpm_file_to_image(root->mlx, path, &width, &height);
	free(path);
	if (*img == 0)
		return (destroy(root, 2, "Error\nCan't load texture"));
	(*img)->width = width;
	(*img)->height = height;
	*buf += len;
	while (**buf && **buf != '\n' && ft_isspace(**buf))
		(*buf)++;
	if (**buf != '\n')
		return (destroy(root, 2, "Error\nInvalid texture path"));
	return (root);
}
