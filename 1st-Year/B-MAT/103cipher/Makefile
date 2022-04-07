##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## 102architect
##

SRC	=	helper_func.c	\
		create_struct.c	\
		matrix_size.c	\
		empty_matrix.c	\
		key_func.c	\
		message_func.c	\
		encryptage_func.c	\
		key_transpo_func.c	\
		key_comatrice_func.c	\
		key_determinant_func.c	\
		key_inverse_func.c	\
		message_encrypted_func.c	\
		decryptage_func.c	\
		main.c

OBJ	=	$(SRC:.c=.o)

NAME 	=	103cipher

CFLAGS	=	-I./include/ -I./include/ -I./include/ -I. -g

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


