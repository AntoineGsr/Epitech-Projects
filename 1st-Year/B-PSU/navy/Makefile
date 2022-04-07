##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## my_ls
##

SRC	=	error_gestion.c	\
		error_boats.c	\
		error_boats2.c	\
		verif_map.c	\
		helper.c	\
		convert_letter.c	\
		convert_nb.c	\
		create_buff.c	\
		create_maps.c	\
		create_struct.c	\
		coord_boats.c	\
		display_map.c	\
		connect_users.c	\
		print_action.c	\
		read_input.c	\
		communication_users.c	\
		receive_message.c	\
		send_message.c	\
		verif_sig_sleep.c	\
		main.c

OBJ	=	$(SRC:.c=.o)

NAME 	=	navy

CFLAGS	=	-I./include/ -I. -g

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


