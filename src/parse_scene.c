#include "cub3d.h"

t_root	*parse_scene(char *buf)
{
	t_root			*root;

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
	root->map = parse_map(root, buf);
	if (root-> map == 0)
		return (0);
	if (check_map(root) == 0)
		return (0);
	return (root);
}
