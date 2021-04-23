#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char *str;
	size_t				i;

	str = s;
	i = -1;
	while (++i < n)
		if (*str++ == c)
			return ((unsigned char *)s + i);
	return (0);
}
