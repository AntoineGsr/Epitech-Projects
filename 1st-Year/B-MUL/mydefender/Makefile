##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## my_defender
##

SRC	=	$(wildcard ./src/*.c)

OBJ	=	$(SRC:.c=.o)

NAME 	=	my_defender

CFLAGS	=	-I./include/ -I./src/ -g

LDFLAGS =	-L./lib/ -lmy -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

all:	$(NAME)

$(NAME):	$(OBJ) lib/libmy.a
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
	$(RM) ./lib/my/*~
	$(RM) *~
	$(RM) $(OBJ)
	$(MAKE) -C ./lib/my/ clean

fclean:	clean
	$(RM) $(NAME)
	$(RM) ./lib/libmy.a
	$(MAKE) -C ./lib/my/ fclean

re:	fclean all

lib/libmy.a:
	$(MAKE) -C ./lib/my/

.Phony: all clean fclean re


