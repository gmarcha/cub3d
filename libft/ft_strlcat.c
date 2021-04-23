#include "libft.h"

static size_t	ft_strsize(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t			src_len;
	size_t			dst_len;
	size_t			i;

	src_len = ft_strsize(src);
	dst_len = ft_strsize(dst);
	if (size)
	{
		i = 0;
		while (src[i] && i + dst_len + 1 < size)
		{
			dst[i + dst_len] = src[i];
			i++;
		}
		dst[i + dst_len] = 0;
	}
	return ((size <= dst_len) ? src_len + size : src_len + dst_len);
}
