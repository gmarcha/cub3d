#include <stdlib.h>

static size_t	ft_strsize(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	size_t			len_s;
	size_t			i;

	len_s = ft_strsize(s);
	if (!(str = (char *)malloc(len + 1)))
		return (0);
	i = 0;
	if (start < len_s)
		while (s[i + start] && i < len)
		{
			str[i] = s[i + start];
			i++;
		}
	str[i] = 0;
	return (str);
}