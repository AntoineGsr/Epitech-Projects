##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## 105torus
##

SRC	=	$(wildcard ./src/*.c)

OBJ	=	$(SRC:.c=.o)

NAME 	=	matchstick

CFLAGS	=	-I./include/ -g

CFLAGS +=	-Wall -Wextra -Wshadow -Wuninitialized -Wformat-security

LDFLAGS =	-L./lib/ -lmy -lncurses

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
	$(MAKE) -C ./lib/my/ .Phony
