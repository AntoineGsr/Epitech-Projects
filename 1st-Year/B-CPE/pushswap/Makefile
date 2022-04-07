##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## my_ls
##

SRC	=	create_list.c	\
		count_nb_args.c	\
		add_to_list.c	\
		add_first.c	\
		del_to_list.c	\
		verif_sort.c	\
		find_minimum.c	\
		rotate_la.c	\
		push_lb.c	\
		bubble_sort.c	\
		sa_func.c	\
		sb_func.c	\
		sc_func.c	\
		pa_func.c	\
		pb_func.c	\
		ra_func.c	\
		rb_func.c	\
		rr_func.c	\
		rra_func.c	\
		rrb_func.c	\
		rrr_func.c	\
		print_action.c	\
		main.c

OBJ	=	$(SRC:.c=.o)

NAME 	=	push_swap

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