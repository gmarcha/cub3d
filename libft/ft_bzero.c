#include "libft.h"

void	*ft_bzero(void *s, size_t n)
{
	unsigned char		*str;
	size_t				i;

	str = s;
	i = -1;
	while (++i < n)
		*str++ = 0;
	return (s);
}
