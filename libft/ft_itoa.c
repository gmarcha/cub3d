#include <stdlib.h>

static int	get_number_size(int n)
{
	int				i;

	i = (n <= 0) ? 1 : 0;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char		*ft_itoa(int n)
{
	char			*nbr;
	unsigned int	nb;
	int				len_nbr;

	len_nbr = get_number_size(n);
	if (!(nbr = (char *)malloc(len_nbr + 1)))
		return (0);
	nbr[len_nbr] = 0;
	nb = (n < 0) ? -n : n;
	while (len_nbr--)
	{
		nbr[len_nbr] = "0123456789"[nb % 10];
		nb /= 10;
	}
	if (n < 0)
		nbr[0] = 45;
	return (nbr);
}