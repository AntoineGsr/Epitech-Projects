##
## EPITECH PROJECT, 2021
## MAKEFILE
## File description:
## MAKEFILE
##

SRC =	$(wildcard *.c)

OBJ	=	$(SRC:.c=.o)

NAME	=	giantman

CFLAGS	=	-I../include/ -g

LDFLAGS =	-L../lib/ -lmy

all:	$(NAME)

$(NAME):	$(OBJ) lib/libmy.a
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
	$(RM) ../lib/my/*~
	$(RM) *~
	$(RM) $(OBJ)
	$(MAKE) -C ../lib/my/ clean

fclean:	clean
	$(RM) $(NAME)
	$(RM) ../lib/libmy.a
	$(MAKE) -C ../lib/my/ fclean

re:	fclean all

lib/libmy.a:
	$(MAKE) -C ../lib/my/

.Phony: all clean fclean re
