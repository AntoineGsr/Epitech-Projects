##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## lib
##

SRC	=	$(wildcard *.c)

OBJ	=	$(SRC:.c=.o)

NAME 	=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc  $(NAME) $(OBJ)
	cp $(NAME) ..

clean:
	rm -f $(OBJ)
	rm -f *~

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.Phony: all clean fclean re
