#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const unsigned char	*s;
	unsigned char		*d;
	size_t				i;

	if (dest == src)
		return (dest);
	d = dest;
	s = src;
	i = -1;
	while (++i < n)
		*d++ = *s++;
	return (dest);
}
