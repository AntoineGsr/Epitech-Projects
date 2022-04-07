##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## 105torus
##

SRC	=	./src/helper.c	\
		./src/error_gestion.c	\
		./src/bisection_method.c	\
		./src/newtons_method.c	\
		./src/secant_method.c	\
		./src/main.c

OBJ	=	$(SRC:.c=.o)

NAME 	=	105torus

CFLAGS	=	-I./include/ -I./src/ -g

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


