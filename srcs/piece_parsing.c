#include "filler.h"

int	parse_piece_line(char *line, t_otherlist **piece, int i, int piece_x)
{
	int		j;
	t_position	tmp;

	j = 0;
	while (line[j] && j < piece_x)
	{
		if (line[j] == '*')
		{
			tmp.y = i;
			tmp.x = j;
			ft_lstprepend(piece, ft_otherlstnew(&tmp, sizeof(tmp)));
		}
		++j;
	}
	return (j == piece_x);
}

t_otherlist		*parse_piece(t_position *dim)
{
	t_otherlist		*piece;
	char		*line;
	int			i;

	if (!get_dimension(&dim->y, &dim->x))
		return (NULL);
	piece = NULL;
	i = 0;
	line = NULL;
	while (i < dim->y && get_next_line(0, &line) == 1)
	{
		if (!parse_piece_line(line, &piece, i, dim->x))
		{
			free(line);
			ft_otherlstdel(&piece, free_block);
			return (NULL);
		}
		free(line);
		i += 1;
	}
	if (i != dim->y)
		ft_otherlstdel(&piece, free_block);
	return (piece);
}