#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char		*str;
	size_t				i;

	str = s;
	i = -1;
	while (++i < n)
		*str++ = c;
	return (s);
}
