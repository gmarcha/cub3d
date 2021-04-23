#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	char			*d;
	int				i;

	i = 0;
	while (s[i])
		i++;
	if (!(d = (char *)malloc(i + 1)))
		return (0);
	i = -1;
	while (s[++i])
		d[i] = s[i];
	d[i] = 0;
	return (d);
}
