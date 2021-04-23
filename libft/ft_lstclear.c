#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list			*tmp;
	t_list			*node;

	if (!*lst)
		return ;
	node = *lst;
	while (node)
	{
		tmp = node;
		node = node->next;
		if (tmp->content)
			del(tmp->content);
		free(tmp);
	}
	*lst = 0;
}
