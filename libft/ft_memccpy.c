#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
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
	{
		*d++ = *s++;
		if (*s == c)
		{
			*d++ = *s++;
			i++;
			return ((char *)dest + i + 1);
		}
	}
	return (0);
}
