##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## lib
##

SRC	=	my_compute_power_rec.c	\
		my_compute_square_root.c	\
		my_find_prime_sup.c		\
		my_getnbr.c		\
		my_isneg.c		\
		my_is_prime.c		\
		my_putchar.c		\
		my_put_nbr.c		\
		my_putstr.c		\
		my_revstr.c		\
		my_showmem.c		\
		my_showstr.c		\
		my_sort_int_array.c	\
		my_strcapitalize.c	\
		my_strcat.c		\
		my_strcmp.c		\
		my_strcpy.c		\
		my_strdup.c		\
		my_str_isalpha.c	\
		my_str_islower.c	\
		my_str_isnum.c		\
		my_str_isprintable.c	\
		my_str_isupper.c	\
		my_strlen.c		\
		my_strlowcase.c		\
		my_strncat.c		\
		my_strncmp.c		\
		my_strncpy.c		\
		my_strstr.c		\
		my_strupcase.c		\
		my_swap.c	\
		my_getstr.c	\
		my_getstr_long.c	\
		integer.c	\
		character.c	\
		string_to_print.c	\
		unsigned_long.c	\
		octal.c	\
		hexa.c	\
		hexa_cap.c	\
		flow.c	\
		pointer_adress.c	\
		binary.c	\
		no_printable.c	\
		pourcent_double.c	\
		nothing_print.c	\
		dot.c	\
		gtnb_pt.c	\
		diez.c	\
		neg_signe.c	\
		pos_or_neg.c	\
		add_a_zero.c	\
		space_to_print.c	\
		width_nb.c	\
		my_printf.c

OBJ	=	$(SRC:.c=.o)

NAME 	=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc  $(NAME) $(OBJ)
	cp $(NAME) ..

clean:
	rm -f $(OBJ)
	rm -f *~

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.Phony: all clean fclean re
