#include "filler.h"

void	ft_lstprepend(t_otherlist **alst, t_otherlist *new)
{
	if (!alst || !new)
		return ;
	new->next = *alst;
	if (*alst)
		new->prev = (*alst)->prev;
	else
		new->prev = NULL;
	*alst = new;
}