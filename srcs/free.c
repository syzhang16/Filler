#include "filler.h"

void	free_block(void *content, size_t content_size)
{
	(void)content_size;
	free(content);
}

void		free_board(int **board)
{
	int i;

	i = 0;
	while (board[i])
	{
		free(board[i]);
		++i;
	}
	free(board);
}