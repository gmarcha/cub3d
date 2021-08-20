/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 19:38:54 by user42            #+#    #+#             */
/*   Updated: 2021/08/18 19:38:54 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	*join_buf(char *file, char *buf)
{
	char			*tmp;

	tmp = ft_strjoin(file, buf);
	free(file);
	return (tmp);
}

static char	*handle_infinite_input(char **file_content, char buf[], size_t i,
	int ret)
{
	if (i > 100 || (i > 2 && ret == 6))
	{
		free(*file_content);
		return (destroy(0, 0, "Error\n/dev/random, "
				"/dev/urandom or /dev/arandom are invalid files"));
	}
	if (*file_content == NULL)
		*file_content = ft_strdup(buf);
	else
		*file_content = join_buf(*file_content, buf);
	if (*file_content == NULL)
		return (destroy(0, 0, "Error\n.cub file reading failed"));
	return (*file_content);
}

static char	*read_file(int fd)
{
	char			*file_content;
	char			buf[4096 + 1];
	int				ret;
	size_t			i;

	i = 0;
	ret = read(fd, buf, 4096);
	if (ret == -1)
		return (destroy(0, 0, "Error\nCan't read the .cub file"));
	if (ret == 0)
		return (destroy(0, 0, "Error\nScene file is empty"));
	file_content = NULL;
	while (ret != 0)
	{
		buf[ret] = 0;
		i++;
		if (handle_infinite_input(&file_content, buf, i, ret) == NULL)
			return (NULL);
		ret = read(fd, buf, 4096);
	}
	return (file_content);
}

t_root	*init_scene(char *file_name)
{
	t_root			*root;
	int				fd;
	char			*file_content;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (destroy(0, 0, "Error\nCan't open the .cub file"));
	file_content = read_file(fd);
	close(fd);
	if (file_content == 0)
		return (0);
	root = parse_scene(file_content);
	free(file_content);
	if (root == 0)
		return (0);
	return (root);
}
