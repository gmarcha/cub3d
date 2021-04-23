#include <unistd.h>

void	ft_putstr_fd(char *s, int fd)
{
	int				i;

	i = 0;
	while (s[i])
		i++;
	write(fd, s, i);
}