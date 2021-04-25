#include "cub3d.h"

t_root				*parse_texture(t_root *root, char **buf, t_img **img)
{
	char			*path;
	int				len;
	int				width;
	int				height;

	if (*img)
		return (destroy(root, 2, "error: multiple texture definition"));
	while (**buf && is_space(**buf))
		(*buf)++;
	len = ft_strclen(*buf, '\n');
	path = ft_substr(*buf, 0, len);
	if (path == 0)
		return (destroy(root, 2, "error: no texture file"));
	*img = mlx_xpm_file_to_image(root->mlx, path, &width, &height);
	free(path);
	if (*img == 0)
		return (destroy(root, 2, "error: can't load texture"));
	(*img)->width = width;
	(*img)->height = height;
	*buf += len;
	if (**buf != '\n')
		return (destroy(root, 2, "error: invalid texture path"));
	return (root);
}
