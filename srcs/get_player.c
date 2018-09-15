#include "filler.h"

int		get_player(void)
{
	int		player;
	char	*line;

	if (get_next_line(0, &line) == 1 && ft_strlen(line) >= 11)
	{
		player = ft_atoi(line + 10);
		if (player == 1 || player == 2)
		{
			free(line);
			return (player);
		}
	}
	free(line);
	return (0);
}