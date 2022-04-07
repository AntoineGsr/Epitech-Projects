##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## 102architect
##

SRC	=	error_gestion.c	\
		translation.c	\
		scaling.c	\
		rotation.c	\
		reflexion.c	\
		main.c

OBJ	=	$(SRC:.c=.o)

NAME 	=	102architect

CFLAGS	=	-I./include/ -I./include/ -I./include/ -I.

LDFLAGS =	-L./lib/ -lmy -lm

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


