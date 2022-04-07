##
## EPITECH PROJECT, 2020
## makefile
## File description:
## Makefile
##

SRC	=	$(wildcard *.c)

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

NAME_H	=	my.h

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	rm -f *.o
	cp $(NAME) ..
	cp $(NAME_H) ../../include/$(NAME_H)
clean:
	rm -f *.o
fclean:		clean
	rm libmy.a
	rm ../libmy.a
re:		fclean all