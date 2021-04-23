#include "libft.h"

void	ft_lstadd_front(t_list **alst, t_list *new)
{
	t_list			*node;

	if (!new)
		return ;
	node = *alst;
	*alst = new;
	(*alst)->next = node;
}