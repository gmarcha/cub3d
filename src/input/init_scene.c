#include "cub3d.h"

static char	*join_buf(char *file, char *buf)
{
	char			*tmp;

	tmp = ft_strjoin(file, buf);
	free(file);
	return (tmp);
}

static char	*read_file(int fd)
{
	char			*file_content;
	char			buf[4096 + 1];
	int				ret;

	ret = read(fd, buf, 4096);
	if (ret == -1)
		return (destroy(0, 0, "error: can't read the .cub file"));
	if (ret == 0)
		return (destroy(0, 0, "error: scene file is empty"));
	file_content = NULL;
	while (ret != 0)
	{
		buf[ret] = 0;
		if (file_content == NULL)
			file_content = ft_strdup(buf);
		else
			file_content = join_buf(file_content, buf);
		if (file_content == NULL)
			return (destroy(0, 0, "error: .cub file reading failed"));
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
		return (destroy(0, 0, "error: can't open the .cub file"));
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