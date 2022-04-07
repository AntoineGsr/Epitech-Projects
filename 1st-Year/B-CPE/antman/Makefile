##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## my_ls
##

NAME 	=	test

CFLAGS	=	-I./include/ -g

LDFLAGS =	-L./lib/ -lmy

all:	$(NAME)

$(NAME):	lib/libmy.a

clean:
	$(RM) ./lib/my/*~
	$(RM) *~
	$(RM) $(OBJ)
	$(MAKE) -C ./lib/my/ clean
	$(MAKE) -C ./antman clean
	$(MAKE) -C ./giantman clean

fclean:	clean
	$(RM) $(NAME)
	$(RM) ./lib/libmy.a
	$(MAKE) -C ./lib/my/ fclean
	$(MAKE) -C ./antman fclean
	$(MAKE) -C ./giantman fclean

re:	fclean all

lib/libmy.a:
	$(MAKE) -C ./lib/my/
	$(MAKE) -C ./antman
	$(MAKE) -C ./giantman

.Phony: all clean fclean re
