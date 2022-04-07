##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## bsq
##

SRC	=	cross_on_map.c	\
		detect_cross.c	\
		fs_read_square.c	\
		is_square_of_size.c	\
		load_2d_arr_from_file.c	\
		loop_char_to_matrix.c	\
		malloc_buff_size.c	\
		main.c

OBJ	=	$(SRC:.c=.o)

NAME 	=	bsq

CFLAGS	=	-I./include/ -I./include/ -I./include/ -I. -I.

LDFLAGS =	-L./lib/ -lmy

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


