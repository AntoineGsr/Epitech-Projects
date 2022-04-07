##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## 105torus
##

SRC	=	./src/create_struct.c	\
		./src/create_nodes.c	\
		./src/destroy_func.c	\
		./src/input_gestion_child.c	\
		./src/input_gestion_father.c	\
		./src/history_gestion.c	\
		./src/my_str_to_word_array.c	\
		./src/my_memsets.c	\
		./src/process_gestion.c	\
		./src/ctrl_c_gestion.c	\
		./src/sig_handlers.c	\
		./src/print_shell.c	\
		./src/fork_gestion.c	\
		./src/compare_command.c	\
		./src/register_input.c	\
		./src/struct_gestion.c	\
		./src/display_l.c	\
		./src/gestion_array_env.c	\
		./src/input_gestion_father_subfunc.c	\
		./src/verif_env_var.c	\
		./src/error_arguments.c	\
		./src/echo_gestion.c	\
		./src/gestion_cd_input.c	\
		./src/gestion_setenv_input.c	\
		./src/gestion_exit_input.c	\
		./src/main.c

OBJ	=	$(SRC:.c=.o)

NAME 	=	mysh

CFLAGS	=	-I./include/ -g

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


