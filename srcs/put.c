#include "filler.h"

int	can_place(t_board b, t_otherlist *piece, t_position current, int p)
{
	int contact;

	contact = 0;
	while (piece)
	{
		if (POS(piece)->y + current.y >= b.y || POS(piece)->y + current.y < 0
			|| POS(piece)->x + current.x >= b.x || POS(piece)->x + current.x < 0)
			return (0);
		if (b.board[current.y + POS(piece)->y][current.x + POS(piece)->x] != 0)
		{
			if (contact
			|| b.board[current.y + POS(piece)->y][current.x + POS(piece)->x] != p)
				return (0);
			++contact;
		}
		piece = piece->next;
	}
	return (contact);
}

int	get_min(t_position tmp_pos, t_otherlist *piece, t_position current)
{
	int		tmpx;
	int		tmpy;
	t_position	tmp;

	tmp.x = POS(piece)->x + current.x;
	tmp.y = POS(piece)->y + current.y;
	tmpx = (tmp.x - tmp_pos.x) * (tmp.x - tmp_pos.x);
	tmpy = (tmp.y - tmp_pos.y) * (tmp.y - tmp_pos.y);
	return (ft_sqrt(tmpx + tmpy));
}

int	get_distance(t_board board, t_otherlist *piece, t_position current, int opponent)
{
	int		d;
	int		min;
	t_position	tmp;

	tmp.y = 0;
	min = INT_MAX;
	while (tmp.y < board.y)
	{
		tmp.x = 0;
		while (tmp.x < board.x)
		{
			if (board.board[tmp.y][tmp.x] == opponent
			&& (d = get_min(tmp, piece, current)) < min)
				min = d;
			++tmp.x;
		}
		++tmp.y;
	}
	return (min);
}

void		place_piece(t_board board, t_otherlist *piece, t_position origin, int player)
{
	int		tmp;
	int		min;
	t_position	min_pos;
	t_position	current;

	min = INT_MAX;
	min_pos.x = 0;
	min_pos.y = 0;
	current.y = -origin.y;
	while (current.y < board.y)
	{
		current.x = -origin.x;
		while (current.x < board.x)
		{
			if (can_place(board, piece, current, player)
			&& (tmp = get_distance(board, piece, current, (player == 1) ? 2 : 1)) < min)
			{
				min_pos = current;
				min = tmp;
			}
			++current.x;
		}
		++current.y;
	}
	ft_printf("%d %d\n", min_pos.y, min_pos.x);
}