#include <stdlib.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	char			*str;
	void			*s;
	size_t			i;

	if (!(s = malloc(nmemb * size)))
		return (0);
	str = s;
	i = 0;
	while (i < nmemb * size)
		str[i++] = 0;
	return (s);
}
