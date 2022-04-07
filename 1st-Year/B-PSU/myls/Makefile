##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## my_ls
##

SRC	=	create_mask_array.c	\
		name_file.c	\
		error_right.c	\
		init_stuct_array.c	\
		print_ls.c	\
		flag_to_exe.c	\
		no_flags.c	\
		type_file.c	\
		create_struct.c	\
		perms_file.c	\
		l_flag.c	\
		r_flag.c	\
		full_array_create.c	\
		empty_full_ls.c	\
		get_my_period.c	\
		total_block.c	\
		main.c

OBJ	=	$(SRC:.c=.o)

NAME 	=	my_ls

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


