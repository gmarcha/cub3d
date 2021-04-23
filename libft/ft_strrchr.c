char	*ft_strrchr(const char *s, int c)
{
	int				i;

	i = 0;
	while (s[i])
		i++;
	while (i--)
		if (s[i] == c)
			return ((char *)s + i);
	return (0);
}
