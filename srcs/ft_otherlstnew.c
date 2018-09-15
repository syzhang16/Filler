#include "filler.h"

t_otherlist	*ft_otherlstnew(void const *content, size_t content_size)
{
	t_otherlist	*new_elem;

	new_elem = (t_otherlist *)malloc(sizeof(t_otherlist));
	if (!new_elem)
		return (NULL);
	new_elem->content = (content) ? malloc(content_size) : NULL;
	if (content && !new_elem->content)
	{
		free(new_elem);
		return (NULL);
	}
	if (content)
		ft_memcpy(new_elem->content, content, content_size);
	new_elem->content_size = (content) ? content_size : 0;
	new_elem->next = NULL;
	new_elem->prev = NULL;
	return (new_elem);
}