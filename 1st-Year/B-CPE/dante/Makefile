##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## my_ls
##

all:
	$(MAKE) -C ./generator
	$(MAKE) -C ./solver

generator:
	$(MAKE) -C ./generator

solver:
	$(MAKE) -C ./solver

clean:
	$(MAKE) -C ./generator clean
	$(MAKE) -C ./solver clean

fclean:	clean
	$(MAKE) -C ./generator fclean
	$(MAKE) -C ./solver fclean

re:	fclean all

.PHONY: all generator solver clean fclean re
