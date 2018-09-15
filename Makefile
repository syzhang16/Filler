NAME = syzhang.filler

SRC_DIR = ./srcs/
OBJ_DIR = ./obj/
CC = gcc
CFLAGS = -Wall -Werror -Wextra $(INCLUDE) -g
CPPFLAGS = -I ./includes -I ./libft/
LDFLAGS = -L libft/
LDLIBS = -lft
LIB = libft/libft.a
MAKE = make
RM = rm -f

HEADER = \
		includes/filler.h \

SRC= \
	board.c \
	free.c \
	ft_otherlstdel.c \
	ft_otherlstnew.c \
	ft_otherlstprepend.c \
	ft_sqrt.c \
	get_player.c \
	main.c \
	piece_parsing.c \
	put.c

OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

all: 
	@$(MAKE) libs 
	@$(MAKE) $(NAME)

$(NAME): $(LIB) $(OBJ)
	@echo "\n\033[94mCompiling filler\033[0m"
	@$(CC) $(CFLAGS) $(CPPFLAGS)  $(OBJ)  -o $(NAME) $(LDFLAGS) $(LDLIBS)
	@echo  "\033[34mDone\033[0m"

$(LIB):;

libs:
	@$(MAKE) -C libft/

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HEADER)
	@mkdir $(OBJ_DIR) 2> /dev/null || true
	@$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

clean:
	@$(MAKE) clean -C libft/
	@$(RM) $(OBJ)
	@rmdir  $(OBJ_DIR) 2> /dev/null || true

fclean: clean
	@$(MAKE) fclean -C libft/
	@$(RM) $(NAME)

re:
	@$(MAKE) fclean
	@$(MAKE) all

.PHONY: clean fclean re all libs