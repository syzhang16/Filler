#include "filler.h"

int			get_dimension(int *y, int *x)
{
	char *line;
	char *tmp;

	if (get_next_line(0, &line) != 1)
		return (0);
	tmp = line;
	while (tmp && !ft_isdigit(*tmp))
		++tmp;
	*y = ft_atoi(tmp);
	while (tmp && ft_isdigit(*tmp))
		++tmp;
	*x = ft_atoi(tmp);
	free(line);
	return (*x && *y);
}
int		parse_board_line(int **board, char *tmp, int i, int x)
{
	int j;

	j = 0;
	while (tmp[j])
	{
		if (tmp[j] == '.')
			board[i][j] = 0;
		else if (tmp[j] == 'O' || tmp[j] == 'o')
			board[i][j] = 1;
		else if (tmp[j] == 'X' || tmp[j] == 'x')
			board[i][j] = 2;
		else
			return (0);
		++j;
	}
	return (j == x);
}

int	parse_board(int **board, int x, int y)
{
	char	*line;
	int		i;

	i = 0;
	while (i < y && get_next_line(0, &line) == 1)
	{
		if (ft_strlen(line) < 5
			|| !(board[i] = (int *)malloc(sizeof(int) * x))
			|| !parse_board_line(board, line + 4, i, x))
		{
			free(line);
			return (0);
		}
		free(line);
		++i;
	}
	return (i == y);
}

int			**init_board(int *x, int *y)
{
	int		**board;
	char	*line;
	int		i;

	if (!get_dimension(y, x)
		|| !(board = (int **)malloc(sizeof(int *) * (*y + 1))))
		return (NULL);
	get_next_line(0, &line);
	free(line);
	i = 0;
	while (i <= *y)
		board[i++] = NULL;
	if (!parse_board(board, *x, *y))
	{
		free_board(board);
		return (NULL);
	}
	return (board);
}