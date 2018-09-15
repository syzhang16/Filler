#include "filler.h"

void	ft_otherlstdel(t_otherlist **alst, void (*del)(void *, size_t))
{
	t_otherlist *tmp;

	if (!alst)
		return ;
	while (*alst)
	{
		tmp = (*alst)->next;
		if (del)
			(*del)((*alst)->content, (*alst)->content_size);
		free(*alst);
		*alst = tmp;
	}
}