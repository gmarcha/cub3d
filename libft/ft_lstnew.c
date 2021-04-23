#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list			*node;

	if (!(node = (t_list *)malloc(sizeof(t_list))))
		return (0);
	node->content = content;
	node->next = 0;
	return (node);
}