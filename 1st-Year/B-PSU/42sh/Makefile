##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## mysh
##

SRC	=	$(wildcard src/*.c) \
		$(wildcard src/42sh/*.c)

OBJ	=	$(SRC:.c=.o)

NAME	=	42sh

CFLAGS	=	-I./ -g -lncurses

all:	$(NAME)

$(NAME):	$(OBJ)
	$(MAKE) -C lib/my/
	$(CC) -o $(NAME) $(OBJ) lib/my/libmy.a $(CFLAGS)

clean:
	$(MAKE) -C lib/my clean
	$(RM) $(OBJ)
	$(RM) *~
	$(RM) .db_l_redirect

fclean:	clean
	$(MAKE) -C lib/my fclean
	$(RM) $(NAME)

re:	fclean all

.Phony:	all clean fclean re
