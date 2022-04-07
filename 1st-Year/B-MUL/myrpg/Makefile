##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## /
##

SRC = $(wildcard ./src/*.c) $(wildcard ./src/DANTE/*.c) $(wildcard ./src/DESTROY/*.c) $(wildcard ./src/END/*.c) $(wildcard ./src/GAME/*.c) $(wildcard ./src/GAME/PARAM/*.c) $(wildcard ./src/GAME/TILE/*.c) $(wildcard ./src/INIT/*.c) $(wildcard ./src/MENU/*.c) $(wildcard ./src/UTILS/*.c)

OBJ	=	$(SRC:.c=.o)

CFLAGS += -g

CFLAGS += -Wall -Wextra -Iinclude

NAME	=	my_rpg

all:	$(OBJ)
	make -sC ./lib/my
	gcc -o $(NAME) $(OBJ) -Llib/my -lmy -lm -lcsfml-graphics -lcsfml-audio -lcsfml-system -lcsfml-window

clean:
	make -sC ./lib/my clean
	rm -f $(OBJ)

fclean:	clean
	make -sC ./lib/my fclean
	rm -f $(NAME)

re:	fclean all