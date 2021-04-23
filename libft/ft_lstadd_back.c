#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list			*node;

	if (!new)
		return ;
	node = *alst;
	while (node->next)
		node = node->next;
	node->next = new;
}