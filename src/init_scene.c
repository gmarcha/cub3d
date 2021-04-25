#include "cub3d.h"

t_root				*init_scene(char *file)
{
	t_root			*root;
	int				fd;
	char			buf[32768 + 1];
	int				ret;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (destroy(0, 0, "error: can't open the scene (*.map)"));
	ret = read(fd, buf, 32768);
	close(fd);
	if (ret == -1)
		return (destroy(0, 0, "error: can't read the scene (*.map)"));
	if (ret == 0)
		return (destroy(0, 0, "error: scene file is empty"));
	buf[ret] = 0;
	root = parse_scene(buf);
	if (root == 0)
		return (0);
	return (root);
}
