#include "filler.h"

int	ft_sqrt(int nb)
{
	int i;

	i = 0;
	while (i * i < nb)
		++i;
	return (i);
}