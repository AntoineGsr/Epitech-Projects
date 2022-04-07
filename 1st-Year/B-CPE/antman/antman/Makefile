##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## my_ls
##

SRC	=	struct_gestion.c	\
		error.c	\
		add_first.c	\
		my_memset_char.c	\
		create_dictionary.c	\
		small_file.c	\
		main.c

OBJ	=	$(SRC:.c=.o)

NAME 	=	antman

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
