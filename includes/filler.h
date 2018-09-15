 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syzhang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 15:10:34 by syzhang           #+#    #+#             */
/*   Updated: 2018/06/28 15:10:47 by syzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <limits.h>
# include "libft.h"

# define POS(x) ((t_position *)x->content)

typedef struct	s_board
{
	int			**board;
	int			x;
	int			y;
}				t_board;

typedef struct	s_position
{
	int			x;
	int			y;
}				t_position;

typedef struct		s_otherlist
{
	void			*content;
	size_t			content_size;
	struct s_otherlist	*next;
	struct s_otherlist	*prev;
}					t_otherlist;

void	free_block(void *content, size_t content_size);
void		free_board(int **board);
int			get_dimension(int *y, int *x);
int		parse_board_line(int **board, char *tmp, int i, int x);
int		parse_board(int **board, int x, int y);
int			**init_board(int *x, int *y);
void	ft_otherlstdel(t_otherlist **alst, void (*del)(void *, size_t));
t_otherlist	*ft_otherlstnew(void const *content, size_t content_size);
void	ft_lstprepend(t_otherlist **alst, t_otherlist *new);
int	ft_sqrt(int nb);
int		get_player(void);
int	parse_piece_line(char *line, t_otherlist **piece, int i, int piece_x);
t_otherlist		*parse_piece(t_position *dim);
int	can_place(t_board b, t_otherlist *piece, t_position current, int p);
int	get_min(t_position tmp_pos, t_otherlist *piece, t_position current);
int	get_dist(t_board board, t_otherlist *piece, t_position current, int opponent);
void		place_piece(t_board board, t_otherlist *piece, t_position origin, int player);

#endif
