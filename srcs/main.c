#include "filler.h"

int				main(void)
{
	int		player;
	t_board	b;
	t_otherlist	*piece;
	t_position	origin;

	if ((player = get_player()) != 1 && player != 2)
		return (1);
	while (1)
	{
		if (!(b.board = init_board(&b.x, &b.y)))
			return (1);
		if (!(piece = parse_piece(&origin)))
		{
			free_board(b.board);
			return (1);
		}
		place_piece(b, piece, origin, player);
		ft_otherlstdel(&piece, free_block);
		free_board(b.board);
	}
	return (0);
}